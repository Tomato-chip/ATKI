// removed package "fpga_template_pkg"
module fft_twiddle_256 (
	clk_i,
	addr_i,
	cos_o,
	sin_o
);
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:12:15
	parameter signed [31:0] DATA_WIDTH = 18;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:14:5
	input wire clk_i;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:15:5
	input wire [7:0] addr_i;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:16:5
	output reg signed [DATA_WIDTH - 1:0] cos_o;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:17:5
	output reg signed [DATA_WIDTH - 1:0] sin_o;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:21:5
	always @(posedge clk_i)
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:22:9
		case (addr_i)
			8'd0: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:23:27
				cos_o = 18'sd131071;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:23:49
				sin_o = 18'sd0;
			end
			8'd1: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:24:27
				cos_o = 18'sd131032;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:24:49
				sin_o = -18'sd3216;
			end
			8'd2: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:25:27
				cos_o = 18'sd130914;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:25:49
				sin_o = -18'sd6431;
			end
			8'd3: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:26:27
				cos_o = 18'sd130716;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:26:49
				sin_o = -18'sd9642;
			end
			8'd4: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:27:27
				cos_o = 18'sd130440;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:27:49
				sin_o = -18'sd12847;
			end
			8'd5: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:28:27
				cos_o = 18'sd130086;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:28:49
				sin_o = -18'sd16044;
			end
			8'd6: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:29:27
				cos_o = 18'sd129653;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:29:49
				sin_o = -18'sd19232;
			end
			8'd7: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:30:27
				cos_o = 18'sd129142;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:30:49
				sin_o = -18'sd22408;
			end
			8'd8: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:31:27
				cos_o = 18'sd128553;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:31:49
				sin_o = -18'sd25570;
			end
			8'd9: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:32:27
				cos_o = 18'sd127887;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:32:49
				sin_o = -18'sd28718;
			end
			8'd10: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:33:28
				cos_o = 18'sd127143;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:33:50
				sin_o = -18'sd31847;
			end
			8'd11: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:34:28
				cos_o = 18'sd126324;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:34:50
				sin_o = -18'sd34958;
			end
			8'd12: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:35:28
				cos_o = 18'sd125428;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:35:50
				sin_o = -18'sd38048;
			end
			8'd13: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:36:28
				cos_o = 18'sd124456;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:36:50
				sin_o = -18'sd41114;
			end
			8'd14: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:37:28
				cos_o = 18'sd123410;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:37:50
				sin_o = -18'sd44156;
			end
			8'd15: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:38:28
				cos_o = 18'sd122289;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:38:50
				sin_o = -18'sd47172;
			end
			8'd16: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:39:28
				cos_o = 18'sd121094;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:39:50
				sin_o = -18'sd50159;
			end
			8'd17: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:40:28
				cos_o = 18'sd119827;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:40:50
				sin_o = -18'sd53115;
			end
			8'd18: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:41:28
				cos_o = 18'sd118487;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:41:50
				sin_o = -18'sd56040;
			end
			8'd19: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:42:28
				cos_o = 18'sd117076;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:42:50
				sin_o = -18'sd58931;
			end
			8'd20: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:43:28
				cos_o = 18'sd115595;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:43:50
				sin_o = -18'sd61786;
			end
			8'd21: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:44:28
				cos_o = 18'sd114044;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:44:50
				sin_o = -18'sd64605;
			end
			8'd22: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:45:28
				cos_o = 18'sd112424;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:45:50
				sin_o = -18'sd67384;
			end
			8'd23: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:46:28
				cos_o = 18'sd110736;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:46:50
				sin_o = -18'sd70123;
			end
			8'd24: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:47:28
				cos_o = 18'sd108982;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:47:50
				sin_o = -18'sd72819;
			end
			8'd25: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:48:28
				cos_o = 18'sd107162;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:48:50
				sin_o = -18'sd75472;
			end
			8'd26: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:49:28
				cos_o = 18'sd105278;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:49:50
				sin_o = -18'sd78079;
			end
			8'd27: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:50:28
				cos_o = 18'sd103330;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:50:50
				sin_o = -18'sd80639;
			end
			8'd28: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:51:28
				cos_o = 18'sd101320;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:51:50
				sin_o = -18'sd83151;
			end
			8'd29: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:52:28
				cos_o = 18'sd99248;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:52:49
				sin_o = -18'sd85612;
			end
			8'd30: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:53:28
				cos_o = 18'sd97117;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:53:49
				sin_o = -18'sd88022;
			end
			8'd31: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:54:28
				cos_o = 18'sd94928;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:54:49
				sin_o = -18'sd90379;
			end
			8'd32: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:55:28
				cos_o = 18'sd92681;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:55:49
				sin_o = -18'sd92681;
			end
			8'd33: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:56:28
				cos_o = 18'sd90379;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:56:49
				sin_o = -18'sd94928;
			end
			8'd34: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:57:28
				cos_o = 18'sd88022;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:57:49
				sin_o = -18'sd97117;
			end
			8'd35: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:58:28
				cos_o = 18'sd85612;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:58:49
				sin_o = -18'sd99248;
			end
			8'd36: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:59:28
				cos_o = 18'sd83151;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:59:49
				sin_o = -18'sd101320;
			end
			8'd37: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:60:28
				cos_o = 18'sd80639;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:60:49
				sin_o = -18'sd103330;
			end
			8'd38: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:61:28
				cos_o = 18'sd78079;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:61:49
				sin_o = -18'sd105278;
			end
			8'd39: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:62:28
				cos_o = 18'sd75472;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:62:49
				sin_o = -18'sd107162;
			end
			8'd40: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:63:28
				cos_o = 18'sd72819;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:63:49
				sin_o = -18'sd108982;
			end
			8'd41: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:64:28
				cos_o = 18'sd70123;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:64:49
				sin_o = -18'sd110736;
			end
			8'd42: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:65:28
				cos_o = 18'sd67384;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:65:49
				sin_o = -18'sd112424;
			end
			8'd43: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:66:28
				cos_o = 18'sd64605;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:66:49
				sin_o = -18'sd114044;
			end
			8'd44: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:67:28
				cos_o = 18'sd61786;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:67:49
				sin_o = -18'sd115595;
			end
			8'd45: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:68:28
				cos_o = 18'sd58931;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:68:49
				sin_o = -18'sd117076;
			end
			8'd46: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:69:28
				cos_o = 18'sd56040;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:69:49
				sin_o = -18'sd118487;
			end
			8'd47: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:70:28
				cos_o = 18'sd53115;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:70:49
				sin_o = -18'sd119827;
			end
			8'd48: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:71:28
				cos_o = 18'sd50159;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:71:49
				sin_o = -18'sd121094;
			end
			8'd49: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:72:28
				cos_o = 18'sd47172;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:72:49
				sin_o = -18'sd122289;
			end
			8'd50: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:73:28
				cos_o = 18'sd44156;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:73:49
				sin_o = -18'sd123410;
			end
			8'd51: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:74:28
				cos_o = 18'sd41114;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:74:49
				sin_o = -18'sd124456;
			end
			8'd52: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:75:28
				cos_o = 18'sd38048;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:75:49
				sin_o = -18'sd125428;
			end
			8'd53: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:76:28
				cos_o = 18'sd34958;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:76:49
				sin_o = -18'sd126324;
			end
			8'd54: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:77:28
				cos_o = 18'sd31847;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:77:49
				sin_o = -18'sd127143;
			end
			8'd55: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:78:28
				cos_o = 18'sd28718;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:78:49
				sin_o = -18'sd127887;
			end
			8'd56: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:79:28
				cos_o = 18'sd25570;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:79:49
				sin_o = -18'sd128553;
			end
			8'd57: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:80:28
				cos_o = 18'sd22408;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:80:49
				sin_o = -18'sd129142;
			end
			8'd58: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:81:28
				cos_o = 18'sd19232;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:81:49
				sin_o = -18'sd129653;
			end
			8'd59: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:82:28
				cos_o = 18'sd16044;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:82:49
				sin_o = -18'sd130086;
			end
			8'd60: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:83:28
				cos_o = 18'sd12847;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:83:49
				sin_o = -18'sd130440;
			end
			8'd61: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:84:28
				cos_o = 18'sd9642;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:84:48
				sin_o = -18'sd130716;
			end
			8'd62: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:85:28
				cos_o = 18'sd6431;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:85:48
				sin_o = -18'sd130914;
			end
			8'd63: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:86:28
				cos_o = 18'sd3216;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:86:48
				sin_o = -18'sd131032;
			end
			8'd64: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:87:28
				cos_o = 18'sd0;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:87:45
				sin_o = -18'sd131072;
			end
			8'd65: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:88:28
				cos_o = -18'sd3216;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:88:49
				sin_o = -18'sd131032;
			end
			8'd66: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:89:28
				cos_o = -18'sd6431;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:89:49
				sin_o = -18'sd130914;
			end
			8'd67: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:90:28
				cos_o = -18'sd9642;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:90:49
				sin_o = -18'sd130716;
			end
			8'd68: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:91:28
				cos_o = -18'sd12847;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:91:50
				sin_o = -18'sd130440;
			end
			8'd69: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:92:28
				cos_o = -18'sd16044;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:92:50
				sin_o = -18'sd130086;
			end
			8'd70: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:93:28
				cos_o = -18'sd19232;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:93:50
				sin_o = -18'sd129653;
			end
			8'd71: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:94:28
				cos_o = -18'sd22408;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:94:50
				sin_o = -18'sd129142;
			end
			8'd72: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:95:28
				cos_o = -18'sd25570;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:95:50
				sin_o = -18'sd128553;
			end
			8'd73: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:96:28
				cos_o = -18'sd28718;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:96:50
				sin_o = -18'sd127887;
			end
			8'd74: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:97:28
				cos_o = -18'sd31847;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:97:50
				sin_o = -18'sd127143;
			end
			8'd75: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:98:28
				cos_o = -18'sd34958;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:98:50
				sin_o = -18'sd126324;
			end
			8'd76: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:99:28
				cos_o = -18'sd38048;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:99:50
				sin_o = -18'sd125428;
			end
			8'd77: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:100:28
				cos_o = -18'sd41114;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:100:50
				sin_o = -18'sd124456;
			end
			8'd78: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:101:28
				cos_o = -18'sd44156;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:101:50
				sin_o = -18'sd123410;
			end
			8'd79: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:102:28
				cos_o = -18'sd47172;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:102:50
				sin_o = -18'sd122289;
			end
			8'd80: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:103:28
				cos_o = -18'sd50159;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:103:50
				sin_o = -18'sd121094;
			end
			8'd81: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:104:28
				cos_o = -18'sd53115;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:104:50
				sin_o = -18'sd119827;
			end
			8'd82: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:105:28
				cos_o = -18'sd56040;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:105:50
				sin_o = -18'sd118487;
			end
			8'd83: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:106:28
				cos_o = -18'sd58931;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:106:50
				sin_o = -18'sd117076;
			end
			8'd84: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:107:28
				cos_o = -18'sd61786;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:107:50
				sin_o = -18'sd115595;
			end
			8'd85: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:108:28
				cos_o = -18'sd64605;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:108:50
				sin_o = -18'sd114044;
			end
			8'd86: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:109:28
				cos_o = -18'sd67384;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:109:50
				sin_o = -18'sd112424;
			end
			8'd87: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:110:28
				cos_o = -18'sd70123;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:110:50
				sin_o = -18'sd110736;
			end
			8'd88: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:111:28
				cos_o = -18'sd72819;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:111:50
				sin_o = -18'sd108982;
			end
			8'd89: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:112:28
				cos_o = -18'sd75472;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:112:50
				sin_o = -18'sd107162;
			end
			8'd90: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:113:28
				cos_o = -18'sd78079;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:113:50
				sin_o = -18'sd105278;
			end
			8'd91: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:114:28
				cos_o = -18'sd80639;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:114:50
				sin_o = -18'sd103330;
			end
			8'd92: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:115:28
				cos_o = -18'sd83151;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:115:50
				sin_o = -18'sd101320;
			end
			8'd93: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:116:28
				cos_o = -18'sd85612;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:116:50
				sin_o = -18'sd99248;
			end
			8'd94: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:117:28
				cos_o = -18'sd88022;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:117:50
				sin_o = -18'sd97117;
			end
			8'd95: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:118:28
				cos_o = -18'sd90379;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:118:50
				sin_o = -18'sd94928;
			end
			8'd96: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:119:28
				cos_o = -18'sd92681;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:119:50
				sin_o = -18'sd92681;
			end
			8'd97: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:120:28
				cos_o = -18'sd94928;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:120:50
				sin_o = -18'sd90379;
			end
			8'd98: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:121:28
				cos_o = -18'sd97117;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:121:50
				sin_o = -18'sd88022;
			end
			8'd99: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:122:28
				cos_o = -18'sd99248;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:122:50
				sin_o = -18'sd85612;
			end
			8'd100: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:123:29
				cos_o = -18'sd101320;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:123:52
				sin_o = -18'sd83151;
			end
			8'd101: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:124:29
				cos_o = -18'sd103330;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:124:52
				sin_o = -18'sd80639;
			end
			8'd102: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:125:29
				cos_o = -18'sd105278;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:125:52
				sin_o = -18'sd78079;
			end
			8'd103: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:126:29
				cos_o = -18'sd107162;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:126:52
				sin_o = -18'sd75472;
			end
			8'd104: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:127:29
				cos_o = -18'sd108982;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:127:52
				sin_o = -18'sd72819;
			end
			8'd105: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:128:29
				cos_o = -18'sd110736;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:128:52
				sin_o = -18'sd70123;
			end
			8'd106: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:129:29
				cos_o = -18'sd112424;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:129:52
				sin_o = -18'sd67384;
			end
			8'd107: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:130:29
				cos_o = -18'sd114044;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:130:52
				sin_o = -18'sd64605;
			end
			8'd108: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:131:29
				cos_o = -18'sd115595;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:131:52
				sin_o = -18'sd61786;
			end
			8'd109: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:132:29
				cos_o = -18'sd117076;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:132:52
				sin_o = -18'sd58931;
			end
			8'd110: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:133:29
				cos_o = -18'sd118487;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:133:52
				sin_o = -18'sd56040;
			end
			8'd111: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:134:29
				cos_o = -18'sd119827;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:134:52
				sin_o = -18'sd53115;
			end
			8'd112: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:135:29
				cos_o = -18'sd121094;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:135:52
				sin_o = -18'sd50159;
			end
			8'd113: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:136:29
				cos_o = -18'sd122289;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:136:52
				sin_o = -18'sd47172;
			end
			8'd114: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:137:29
				cos_o = -18'sd123410;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:137:52
				sin_o = -18'sd44156;
			end
			8'd115: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:138:29
				cos_o = -18'sd124456;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:138:52
				sin_o = -18'sd41114;
			end
			8'd116: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:139:29
				cos_o = -18'sd125428;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:139:52
				sin_o = -18'sd38048;
			end
			8'd117: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:140:29
				cos_o = -18'sd126324;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:140:52
				sin_o = -18'sd34958;
			end
			8'd118: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:141:29
				cos_o = -18'sd127143;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:141:52
				sin_o = -18'sd31847;
			end
			8'd119: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:142:29
				cos_o = -18'sd127887;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:142:52
				sin_o = -18'sd28718;
			end
			8'd120: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:143:29
				cos_o = -18'sd128553;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:143:52
				sin_o = -18'sd25570;
			end
			8'd121: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:144:29
				cos_o = -18'sd129142;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:144:52
				sin_o = -18'sd22408;
			end
			8'd122: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:145:29
				cos_o = -18'sd129653;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:145:52
				sin_o = -18'sd19232;
			end
			8'd123: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:146:29
				cos_o = -18'sd130086;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:146:52
				sin_o = -18'sd16044;
			end
			8'd124: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:147:29
				cos_o = -18'sd130440;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:147:52
				sin_o = -18'sd12847;
			end
			8'd125: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:148:29
				cos_o = -18'sd130716;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:148:52
				sin_o = -18'sd9642;
			end
			8'd126: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:149:29
				cos_o = -18'sd130914;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:149:52
				sin_o = -18'sd6431;
			end
			8'd127: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:150:29
				cos_o = -18'sd131032;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:150:52
				sin_o = -18'sd3216;
			end
			8'd128: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:151:29
				cos_o = -18'sd131072;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:151:52
				sin_o = 18'sd0;
			end
			8'd129: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:152:29
				cos_o = -18'sd131032;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:152:52
				sin_o = 18'sd3216;
			end
			8'd130: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:153:29
				cos_o = -18'sd130914;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:153:52
				sin_o = 18'sd6431;
			end
			8'd131: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:154:29
				cos_o = -18'sd130716;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:154:52
				sin_o = 18'sd9642;
			end
			8'd132: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:155:29
				cos_o = -18'sd130440;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:155:52
				sin_o = 18'sd12847;
			end
			8'd133: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:156:29
				cos_o = -18'sd130086;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:156:52
				sin_o = 18'sd16044;
			end
			8'd134: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:157:29
				cos_o = -18'sd129653;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:157:52
				sin_o = 18'sd19232;
			end
			8'd135: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:158:29
				cos_o = -18'sd129142;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:158:52
				sin_o = 18'sd22408;
			end
			8'd136: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:159:29
				cos_o = -18'sd128553;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:159:52
				sin_o = 18'sd25570;
			end
			8'd137: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:160:29
				cos_o = -18'sd127887;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:160:52
				sin_o = 18'sd28718;
			end
			8'd138: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:161:29
				cos_o = -18'sd127143;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:161:52
				sin_o = 18'sd31847;
			end
			8'd139: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:162:29
				cos_o = -18'sd126324;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:162:52
				sin_o = 18'sd34958;
			end
			8'd140: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:163:29
				cos_o = -18'sd125428;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:163:52
				sin_o = 18'sd38048;
			end
			8'd141: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:164:29
				cos_o = -18'sd124456;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:164:52
				sin_o = 18'sd41114;
			end
			8'd142: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:165:29
				cos_o = -18'sd123410;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:165:52
				sin_o = 18'sd44156;
			end
			8'd143: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:166:29
				cos_o = -18'sd122289;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:166:52
				sin_o = 18'sd47172;
			end
			8'd144: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:167:29
				cos_o = -18'sd121094;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:167:52
				sin_o = 18'sd50159;
			end
			8'd145: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:168:29
				cos_o = -18'sd119827;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:168:52
				sin_o = 18'sd53115;
			end
			8'd146: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:169:29
				cos_o = -18'sd118487;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:169:52
				sin_o = 18'sd56040;
			end
			8'd147: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:170:29
				cos_o = -18'sd117076;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:170:52
				sin_o = 18'sd58931;
			end
			8'd148: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:171:29
				cos_o = -18'sd115595;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:171:52
				sin_o = 18'sd61786;
			end
			8'd149: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:172:29
				cos_o = -18'sd114044;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:172:52
				sin_o = 18'sd64605;
			end
			8'd150: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:173:29
				cos_o = -18'sd112424;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:173:52
				sin_o = 18'sd67384;
			end
			8'd151: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:174:29
				cos_o = -18'sd110736;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:174:52
				sin_o = 18'sd70123;
			end
			8'd152: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:175:29
				cos_o = -18'sd108982;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:175:52
				sin_o = 18'sd72819;
			end
			8'd153: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:176:29
				cos_o = -18'sd107162;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:176:52
				sin_o = 18'sd75472;
			end
			8'd154: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:177:29
				cos_o = -18'sd105278;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:177:52
				sin_o = 18'sd78079;
			end
			8'd155: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:178:29
				cos_o = -18'sd103330;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:178:52
				sin_o = 18'sd80639;
			end
			8'd156: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:179:29
				cos_o = -18'sd101320;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:179:52
				sin_o = 18'sd83151;
			end
			8'd157: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:180:29
				cos_o = -18'sd99248;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:180:51
				sin_o = 18'sd85612;
			end
			8'd158: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:181:29
				cos_o = -18'sd97117;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:181:51
				sin_o = 18'sd88022;
			end
			8'd159: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:182:29
				cos_o = -18'sd94928;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:182:51
				sin_o = 18'sd90379;
			end
			8'd160: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:183:29
				cos_o = -18'sd92681;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:183:51
				sin_o = 18'sd92681;
			end
			8'd161: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:184:29
				cos_o = -18'sd90379;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:184:51
				sin_o = 18'sd94928;
			end
			8'd162: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:185:29
				cos_o = -18'sd88022;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:185:51
				sin_o = 18'sd97117;
			end
			8'd163: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:186:29
				cos_o = -18'sd85612;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:186:51
				sin_o = 18'sd99248;
			end
			8'd164: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:187:29
				cos_o = -18'sd83151;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:187:51
				sin_o = 18'sd101320;
			end
			8'd165: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:188:29
				cos_o = -18'sd80639;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:188:51
				sin_o = 18'sd103330;
			end
			8'd166: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:189:29
				cos_o = -18'sd78079;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:189:51
				sin_o = 18'sd105278;
			end
			8'd167: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:190:29
				cos_o = -18'sd75472;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:190:51
				sin_o = 18'sd107162;
			end
			8'd168: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:191:29
				cos_o = -18'sd72819;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:191:51
				sin_o = 18'sd108982;
			end
			8'd169: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:192:29
				cos_o = -18'sd70123;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:192:51
				sin_o = 18'sd110736;
			end
			8'd170: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:193:29
				cos_o = -18'sd67384;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:193:51
				sin_o = 18'sd112424;
			end
			8'd171: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:194:29
				cos_o = -18'sd64605;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:194:51
				sin_o = 18'sd114044;
			end
			8'd172: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:195:29
				cos_o = -18'sd61786;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:195:51
				sin_o = 18'sd115595;
			end
			8'd173: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:196:29
				cos_o = -18'sd58931;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:196:51
				sin_o = 18'sd117076;
			end
			8'd174: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:197:29
				cos_o = -18'sd56040;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:197:51
				sin_o = 18'sd118487;
			end
			8'd175: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:198:29
				cos_o = -18'sd53115;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:198:51
				sin_o = 18'sd119827;
			end
			8'd176: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:199:29
				cos_o = -18'sd50159;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:199:51
				sin_o = 18'sd121094;
			end
			8'd177: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:200:29
				cos_o = -18'sd47172;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:200:51
				sin_o = 18'sd122289;
			end
			8'd178: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:201:29
				cos_o = -18'sd44156;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:201:51
				sin_o = 18'sd123410;
			end
			8'd179: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:202:29
				cos_o = -18'sd41114;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:202:51
				sin_o = 18'sd124456;
			end
			8'd180: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:203:29
				cos_o = -18'sd38048;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:203:51
				sin_o = 18'sd125428;
			end
			8'd181: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:204:29
				cos_o = -18'sd34958;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:204:51
				sin_o = 18'sd126324;
			end
			8'd182: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:205:29
				cos_o = -18'sd31847;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:205:51
				sin_o = 18'sd127143;
			end
			8'd183: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:206:29
				cos_o = -18'sd28718;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:206:51
				sin_o = 18'sd127887;
			end
			8'd184: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:207:29
				cos_o = -18'sd25570;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:207:51
				sin_o = 18'sd128553;
			end
			8'd185: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:208:29
				cos_o = -18'sd22408;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:208:51
				sin_o = 18'sd129142;
			end
			8'd186: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:209:29
				cos_o = -18'sd19232;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:209:51
				sin_o = 18'sd129653;
			end
			8'd187: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:210:29
				cos_o = -18'sd16044;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:210:51
				sin_o = 18'sd130086;
			end
			8'd188: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:211:29
				cos_o = -18'sd12847;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:211:51
				sin_o = 18'sd130440;
			end
			8'd189: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:212:29
				cos_o = -18'sd9642;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:212:50
				sin_o = 18'sd130716;
			end
			8'd190: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:213:29
				cos_o = -18'sd6431;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:213:50
				sin_o = 18'sd130914;
			end
			8'd191: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:214:29
				cos_o = -18'sd3216;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:214:50
				sin_o = 18'sd131032;
			end
			8'd192: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:215:29
				cos_o = 18'sd0;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:215:46
				sin_o = 18'sd131071;
			end
			8'd193: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:216:29
				cos_o = 18'sd3216;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:216:49
				sin_o = 18'sd131032;
			end
			8'd194: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:217:29
				cos_o = 18'sd6431;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:217:49
				sin_o = 18'sd130914;
			end
			8'd195: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:218:29
				cos_o = 18'sd9642;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:218:49
				sin_o = 18'sd130716;
			end
			8'd196: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:219:29
				cos_o = 18'sd12847;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:219:50
				sin_o = 18'sd130440;
			end
			8'd197: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:220:29
				cos_o = 18'sd16044;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:220:50
				sin_o = 18'sd130086;
			end
			8'd198: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:221:29
				cos_o = 18'sd19232;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:221:50
				sin_o = 18'sd129653;
			end
			8'd199: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:222:29
				cos_o = 18'sd22408;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:222:50
				sin_o = 18'sd129142;
			end
			8'd200: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:223:29
				cos_o = 18'sd25570;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:223:50
				sin_o = 18'sd128553;
			end
			8'd201: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:224:29
				cos_o = 18'sd28718;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:224:50
				sin_o = 18'sd127887;
			end
			8'd202: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:225:29
				cos_o = 18'sd31847;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:225:50
				sin_o = 18'sd127143;
			end
			8'd203: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:226:29
				cos_o = 18'sd34958;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:226:50
				sin_o = 18'sd126324;
			end
			8'd204: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:227:29
				cos_o = 18'sd38048;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:227:50
				sin_o = 18'sd125428;
			end
			8'd205: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:228:29
				cos_o = 18'sd41114;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:228:50
				sin_o = 18'sd124456;
			end
			8'd206: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:229:29
				cos_o = 18'sd44156;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:229:50
				sin_o = 18'sd123410;
			end
			8'd207: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:230:29
				cos_o = 18'sd47172;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:230:50
				sin_o = 18'sd122289;
			end
			8'd208: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:231:29
				cos_o = 18'sd50159;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:231:50
				sin_o = 18'sd121094;
			end
			8'd209: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:232:29
				cos_o = 18'sd53115;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:232:50
				sin_o = 18'sd119827;
			end
			8'd210: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:233:29
				cos_o = 18'sd56040;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:233:50
				sin_o = 18'sd118487;
			end
			8'd211: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:234:29
				cos_o = 18'sd58931;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:234:50
				sin_o = 18'sd117076;
			end
			8'd212: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:235:29
				cos_o = 18'sd61786;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:235:50
				sin_o = 18'sd115595;
			end
			8'd213: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:236:29
				cos_o = 18'sd64605;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:236:50
				sin_o = 18'sd114044;
			end
			8'd214: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:237:29
				cos_o = 18'sd67384;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:237:50
				sin_o = 18'sd112424;
			end
			8'd215: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:238:29
				cos_o = 18'sd70123;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:238:50
				sin_o = 18'sd110736;
			end
			8'd216: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:239:29
				cos_o = 18'sd72819;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:239:50
				sin_o = 18'sd108982;
			end
			8'd217: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:240:29
				cos_o = 18'sd75472;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:240:50
				sin_o = 18'sd107162;
			end
			8'd218: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:241:29
				cos_o = 18'sd78079;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:241:50
				sin_o = 18'sd105278;
			end
			8'd219: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:242:29
				cos_o = 18'sd80639;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:242:50
				sin_o = 18'sd103330;
			end
			8'd220: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:243:29
				cos_o = 18'sd83151;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:243:50
				sin_o = 18'sd101320;
			end
			8'd221: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:244:29
				cos_o = 18'sd85612;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:244:50
				sin_o = 18'sd99248;
			end
			8'd222: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:245:29
				cos_o = 18'sd88022;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:245:50
				sin_o = 18'sd97117;
			end
			8'd223: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:246:29
				cos_o = 18'sd90379;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:246:50
				sin_o = 18'sd94928;
			end
			8'd224: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:247:29
				cos_o = 18'sd92681;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:247:50
				sin_o = 18'sd92681;
			end
			8'd225: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:248:29
				cos_o = 18'sd94928;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:248:50
				sin_o = 18'sd90379;
			end
			8'd226: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:249:29
				cos_o = 18'sd97117;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:249:50
				sin_o = 18'sd88022;
			end
			8'd227: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:250:29
				cos_o = 18'sd99248;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:250:50
				sin_o = 18'sd85612;
			end
			8'd228: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:251:29
				cos_o = 18'sd101320;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:251:51
				sin_o = 18'sd83151;
			end
			8'd229: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:252:29
				cos_o = 18'sd103330;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:252:51
				sin_o = 18'sd80639;
			end
			8'd230: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:253:29
				cos_o = 18'sd105278;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:253:51
				sin_o = 18'sd78079;
			end
			8'd231: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:254:29
				cos_o = 18'sd107162;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:254:51
				sin_o = 18'sd75472;
			end
			8'd232: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:255:29
				cos_o = 18'sd108982;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:255:51
				sin_o = 18'sd72819;
			end
			8'd233: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:256:29
				cos_o = 18'sd110736;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:256:51
				sin_o = 18'sd70123;
			end
			8'd234: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:257:29
				cos_o = 18'sd112424;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:257:51
				sin_o = 18'sd67384;
			end
			8'd235: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:258:29
				cos_o = 18'sd114044;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:258:51
				sin_o = 18'sd64605;
			end
			8'd236: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:259:29
				cos_o = 18'sd115595;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:259:51
				sin_o = 18'sd61786;
			end
			8'd237: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:260:29
				cos_o = 18'sd117076;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:260:51
				sin_o = 18'sd58931;
			end
			8'd238: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:261:29
				cos_o = 18'sd118487;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:261:51
				sin_o = 18'sd56040;
			end
			8'd239: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:262:29
				cos_o = 18'sd119827;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:262:51
				sin_o = 18'sd53115;
			end
			8'd240: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:263:29
				cos_o = 18'sd121094;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:263:51
				sin_o = 18'sd50159;
			end
			8'd241: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:264:29
				cos_o = 18'sd122289;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:264:51
				sin_o = 18'sd47172;
			end
			8'd242: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:265:29
				cos_o = 18'sd123410;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:265:51
				sin_o = 18'sd44156;
			end
			8'd243: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:266:29
				cos_o = 18'sd124456;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:266:51
				sin_o = 18'sd41114;
			end
			8'd244: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:267:29
				cos_o = 18'sd125428;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:267:51
				sin_o = 18'sd38048;
			end
			8'd245: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:268:29
				cos_o = 18'sd126324;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:268:51
				sin_o = 18'sd34958;
			end
			8'd246: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:269:29
				cos_o = 18'sd127143;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:269:51
				sin_o = 18'sd31847;
			end
			8'd247: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:270:29
				cos_o = 18'sd127887;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:270:51
				sin_o = 18'sd28718;
			end
			8'd248: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:271:29
				cos_o = 18'sd128553;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:271:51
				sin_o = 18'sd25570;
			end
			8'd249: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:272:29
				cos_o = 18'sd129142;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:272:51
				sin_o = 18'sd22408;
			end
			8'd250: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:273:29
				cos_o = 18'sd129653;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:273:51
				sin_o = 18'sd19232;
			end
			8'd251: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:274:29
				cos_o = 18'sd130086;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:274:51
				sin_o = 18'sd16044;
			end
			8'd252: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:275:29
				cos_o = 18'sd130440;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:275:51
				sin_o = 18'sd12847;
			end
			8'd253: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:276:29
				cos_o = 18'sd130716;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:276:51
				sin_o = 18'sd9642;
			end
			8'd254: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:277:29
				cos_o = 18'sd130914;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:277:51
				sin_o = 18'sd6431;
			end
			8'd255: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:278:29
				cos_o = 18'sd131032;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_twiddle_256.sv:278:51
				sin_o = 18'sd3216;
			end
		endcase
endmodule
