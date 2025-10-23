module pingpong_sp_ram #(
    parameter int unsigned WIDTH = 16,
    parameter int unsigned DEPTH = 10
) (
    input  logic               clk_i,
    input  logic               rst_ni,             // synkron, aktiv-lav

    input  logic [WIDTH-1:0]   sample_i,
    input  logic               sample_ready_i,     // 1 = "én sample klar" (skriv)

    output logic [WIDTH-1:0]   read_data_o,
    output logic               buffer_ready_o      // ét-clock pulse når en buffer er fyldt
    // input  logic            fft_address_sel      // puls fra fft, når den har læst data
);

    localparam int unsigned AW = 8;  // log2(256)

    function automatic logic [13:0] pack_addr(input logic [AW-1:0] a8);
        pack_addr = {2'b00, a8, 4'b0000};
    endfunction

    // Styring
    logic [AW-1:0] write_address, read_address;
    logic          rw_sel;                  // 0: skriv RAM0/læs RAM1, 1: skriv RAM1/læs RAM0
    logic          rw_sel_read;             // Delayed version for output mux (avoid race)
    logic          valid_read_out;
    logic          buffer_full;
    logic          sample_ready;

    assign sample_ready = sample_ready_i;
    assign buffer_full  = sample_ready && (write_address == DEPTH-1);

    always_ff @(posedge clk_i) begin
        if (!rst_ni) begin
            write_address       <= '0;
            read_address        <= '0;
            rw_sel              <= 1'b0;     // start: skriv RAM0, læs RAM1
            rw_sel_read         <= 1'b1;     // start: læs fra RAM1
            valid_read_out      <= 1'b0;
            buffer_ready_o      <= 1'b0;
        end else begin
            buffer_ready_o      <= 1'b0;

            // write addr
            if (sample_ready) begin
                if (buffer_full) write_address <= '0;
                else             write_address <= write_address + 1'b1;
            end

            // read addr (kører i takt med sampling når der findes en fuld blok)
            if (sample_ready && valid_read_out) begin
                if (read_address == DEPTH-1) read_address <= '0;
                else                         read_address <= read_address + 1'b1;
            end

            // blok færdig
            if (buffer_full) begin
                buffer_ready_o      <= 1'b1;                // pulser 1 clk
                valid_read_out      <= 1'b1;
                read_address        <= '0;
                rw_sel              <= ~rw_sel;             // Skift mellem RAM0 og RAM1
                rw_sel_read         <= rw_sel;              // Update read selector (will point to just-filled buffer)
            end
        end
    end

    // AD/WRE pr. RAM - unified control
    logic [13:0] address_RAM_0, address_RAM_1;
    wire         write_enable_RAM_0 = sample_ready && (rw_sel == 1'b0);
    wire         write_enable_RAM_1 = sample_ready && (rw_sel == 1'b1);

    always_comb begin
        // defaults
        address_RAM_0 = '0;
        address_RAM_1 = '0;

        if (rw_sel == 1'b0) begin
            // RAM0 skriver, RAM1 læser
            address_RAM_0 = pack_addr(write_address);
            address_RAM_1 = pack_addr(read_address);
        end else begin
            // RAM1 skriver, RAM0 læser
            address_RAM_0 = pack_addr(read_address);
            address_RAM_1 = pack_addr(write_address);
        end
    end

  // Fysiske RAM
  logic [WIDTH-1:0] data_out_RAM_0, data_out_RAM_1;

    SP u_ram0 (
        .DO     (data_out_RAM_0),
        .CLK    (clk_i),
        .CE     (1'b1),
        .OCE    (1'b0),
        .RESET  (!rst_ni),
        .WRE    (write_enable_RAM_0),
        .BLKSEL (3'b000),
        .AD     (address_RAM_0),
        .DI     (sample_i)
    );
    defparam u_ram0.BIT_WIDTH  = 16;
    defparam u_ram0.READ_MODE  = 1'b0;    // BYPASS
    defparam u_ram0.WRITE_MODE = 2'b00;   // NORMAL
    defparam u_ram0.BLK_SEL    = 3'b000;

    SP u_ram1 (
        .DO     (data_out_RAM_1),
        .CLK    (clk_i),
        .CE     (1'b1),
        .OCE    (1'b0),
        .RESET  (!rst_ni),
        .WRE    (write_enable_RAM_1),
        .BLKSEL (3'b000),
        .AD     (address_RAM_1),
        .DI     (sample_i)
    );
    defparam u_ram1.BIT_WIDTH  = 16;
    defparam u_ram1.READ_MODE  = 1'b0;    // BYPASS
    defparam u_ram1.WRITE_MODE = 2'b00;   // NORMAL
    defparam u_ram1.BLK_SEL    = 3'b000;

    // Output-mux: vælg den buffer, der læses fra
    // Bruger rw_sel_read (delayed) for at undgå race condition ved buffer swap
    always_comb begin
        read_data_o = '0;
        if (valid_read_out) begin
            // rw_sel_read=0 => læs RAM0
            // rw_sel_read=1 => læs RAM1
            read_data_o = (rw_sel_read == 1'b0) ? data_out_RAM_0 : data_out_RAM_1;
        end
    end

endmodule
