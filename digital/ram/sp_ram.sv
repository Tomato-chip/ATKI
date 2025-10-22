module pingpong_sp_ram #(
    parameter int unsigned WIDTH = 16,
    parameter int unsigned DEPTH = 256
) (
    input  logic               clk_i,
    input  logic               rst_ni,             // synkron, aktiv-lav

    input  logic [WIDTH-1:0]   sample_i,
    input  logic               sample_ready_i,     // 1 = "én sample klar" (skriv)

    output logic [WIDTH-1:0]   read_data_o,
    output logic               buffer_ready_o,     // ét-clock pulse når en buffer er fyldt
    output logic               read_enable_o,      // HIGH = data tilgængelig til læsning
    input  logic               read_ack_i          // puls fra læser for at avancere til næste sample

);

    localparam int unsigned AW = 8;  // log2(256)

    function automatic logic [13:0] pack_addr(input logic [AW-1:0] a8);
        pack_addr = {2'b00, a8, 4'b0000};
    endfunction

    // Styring
    logic [AW-1:0]   write_address, read_address;
    logic [AW:0]     read_count;              // Tæller antal læste samples (needs AW+1 bits for 0..DEPTH)
    logic          write_buffer_sel;        // 0: skriv RAM0, 1: skriv RAM1
    logic          read_buffer_sel;         // 0: læs   RAM0, 1: læs  RAM1
    logic          valid_read_out;          // Internt: buffer klar til læsning
    logic          read_in_progress;        // Læsning er startet men ikke færdig
    logic          buffer_full;
    logic          sample_ready;

    assign sample_ready = sample_ready_i;
    assign buffer_full  = sample_ready && (write_address == DEPTH-1);
    assign read_enable_o = valid_read_out && !read_in_progress;  // Data tilgængelig og ikke læst endnu

    always_ff @(posedge clk_i) begin
        if (!rst_ni) begin
            write_address       <= '0;
            read_address        <= '0;
            read_count          <= '0;
            write_buffer_sel    <= 1'b0;     // start: skriv RAM0
            read_buffer_sel     <= 1'b1;     // start: læs RAM1 (tom indtil første blok)
            valid_read_out      <= 1'b0;
            read_in_progress    <= 1'b0;
            buffer_ready_o      <= 1'b0;
        end else begin
            buffer_ready_o      <= 1'b0;

            // write addr
            if (sample_ready) begin
                if (buffer_full) write_address <= '0;
                else             write_address <= write_address + 1'b1;
            end

            // read addr og tæller (avancerer kun når læseren bekræfter med read_ack_i)
            if (read_ack_i && valid_read_out && !read_in_progress) begin
                read_count   <= read_count + 1'b1;
                read_address <= read_address + 1'b1;
                // Markér som færdig når vi har ACK'et DEPTH gange (læst alle 256 samples)
                // Note: counter værdi efter denne ack vil være (read_count+1)
                if ((read_count + 1'b1) == DEPTH) begin
                    read_in_progress <= 1'b1;  // Alle DEPTH samples er nu ACK'et
                end
            end

            // blok færdig - ny buffer klar til læsning
            if (buffer_full) begin
                buffer_ready_o      <= 1'b1;                // pulser 1 clk
                valid_read_out      <= 1'b1;
                read_address        <= '0;
                read_count          <= '0;                  // Nulstil tæller for ny buffer
                read_in_progress    <= 1'b0;                // Nulstil læsestatus for ny buffer
                read_buffer_sel     <= write_buffer_sel;    // Læs fra den buffer der netop blev fyldt
                write_buffer_sel    <= ~write_buffer_sel;   // skriv til den anden fremover
            end
        end
    end

    // AD/WRE pr. RAM
    logic [13:0] address_RAM_0, address_RAM_1;
    wire         write_enable_RAM_0 = sample_ready && (write_buffer_sel == 1'b0);
    wire         write_enable_RAM_1 = sample_ready && (write_buffer_sel == 1'b1);

    always_comb begin
        // defaults
        address_RAM_0 = '0;
        address_RAM_1 = '0;

        if (write_buffer_sel == 1'b0) begin
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
    // logic [16-1:0] data_out_RAM_16_0, data_out_RAM_16_1;
    logic [32-1:0] data_out_RAM_32_0, data_out_RAM_32_1;

    assign data_out_RAM_16_0 = data_out_RAM_32_0[15:0];
    assign data_out_RAM_16_1 = data_out_RAM_32_1[15:0];
    
    SP u_ram0 (
        .DO     (data_out_RAM_32_0),
        .CLK    (clk_i),
        .CE     (1'b1),
        .OCE    (1'b1),          // Skal være HIGH for at aktivere output
        .RESET  (!rst_ni),
        .WRE    (write_enable_RAM_0),
        .BLKSEL (3'b000),
        .AD     (address_RAM_0),
        .DI     ({16'b0, sample_i})
    );
    defparam u_ram0.BIT_WIDTH  = 16;
    defparam u_ram0.READ_MODE  = 1'b1;    // BYPASS
    defparam u_ram0.WRITE_MODE = 2'b00;   // NORMAL
    defparam u_ram0.BLK_SEL    = 3'b000;
    defparam u_ram0.RESET_MODE = "SYNC";
    defparam u_ram0.INIT_RAM_00 =256'h00A000000000000B00A000000000000B00A000000000000B00A000000000000B;
    defparam u_ram0.INIT_RAM_01 = 256'h00A000000000000B00A000000000000B00A000000000000B00A000000000000B;
    defparam u_ram0.INIT_RAM_3F = 256'h00A000000000000B00A000000000000B00A000000000000B00A000000000000B;

    SP u_ram1 (
        .DO     (data_out_RAM_32_1),
        .CLK    (clk_i),
        .CE     (1'b1),
        .OCE    (1'b1),          // Skal være HIGH for at aktivere output
        .RESET  (!rst_ni),
        .WRE    (write_enable_RAM_1),
        .BLKSEL (3'b000),
        .AD     (address_RAM_1),
        .DI     ({16'b0, sample_i})
    );
    defparam u_ram1.BIT_WIDTH  = 16;
    defparam u_ram1.READ_MODE  = 1'b1;    // BYPASS
    defparam u_ram1.WRITE_MODE = 2'b00;   // NORMAL
    defparam u_ram1.BLK_SEL    = 3'b000;
    defparam u_ram1.RESET_MODE = "SYNC";
    defparam u_ram1.INIT_RAM_00 =256'h00A000000000000B00A000000000000B00A000000000000B00A000000000000B;
    defparam u_ram1.INIT_RAM_01 = 256'h00A000000000000B00A000000000000B00A000000000000B00A000000000000B;
    defparam u_ram1.INIT_RAM_3F = 256'h00A000000000000B00A000000000000B00A000000000000B00A000000000000B;

    // Output-mux: vælg den buffer, der blev gjort klar ved sidste blokskift
    always_comb begin
        read_data_o = '0;
        if (valid_read_out) begin
            read_data_o = (read_buffer_sel == 1'b0) ? data_out_RAM_32_0[15:0] : data_out_RAM_32_1[15:0];
        end
    end

endmodule
