// ============================================================================
// fft_twiddle_256 - Twiddle Factor ROM for 256-Point FFT
// ============================================================================
// Precomputed twiddle factors (complex exponentials) for FFT
//
// Twiddle factors: W_N^k = e^(-j*2*pi*k/N) = cos(2πk/N) - j*sin(2πk/N)
// Format: Q1.23 (24-bit signed fixed-point, 23 fractional bits)
// Range: -1.0 to +0.999999881 represented as -8388608 to +8388607
//
// Generation (Python):
// import numpy as np
// N = 256
// for k in range(N):
//     angle = -2 * np.pi * k / N
//     cos_val = int(np.cos(angle) * (2**23))
//     sin_val = int(np.sin(angle) * (2**23))
//     print(f"8'd{k}: begin cos_o = 24'sd{cos_val}; sin_o = 24'sd{sin_val}; end")
// ============================================================================

module fft_twiddle_256 #(
    parameter int DATA_WIDTH = 24
) (
    input  logic                    clk_i,
    input  logic [7:0]              addr_i,     // Twiddle factor index (0-255)
    output logic signed [DATA_WIDTH-1:0] cos_o, // Real part (cosine)
    output logic signed [DATA_WIDTH-1:0] sin_o  // Imaginary part (-sine for FFT)
);

    // Synchronous ROM
    always_ff @(posedge clk_i) begin
        case (addr_i)
            8'd0:   begin cos_o = 24'sd8388607;  sin_o = 24'sd0; end
            8'd1:   begin cos_o = 24'sd8388020;  sin_o = -24'sd205887; end
            8'd2:   begin cos_o = 24'sd8385866;  sin_o = -24'sd411706; end
            8'd3:   begin cos_o = 24'sd8382145;  sin_o = -24'sd617390; end
            8'd4:   begin cos_o = 24'sd8376856;  sin_o = -24'sd822872; end
            8'd5:   begin cos_o = 24'sd8370001;  sin_o = -24'sd1028086; end
            8'd6:   begin cos_o = 24'sd8361580;  sin_o = -24'sd1232966; end
            8'd7:   begin cos_o = 24'sd8351595;  sin_o = -24'sd1437447; end
            8'd8:   begin cos_o = 24'sd8340046;  sin_o = -24'sd1641464; end
            8'd9:   begin cos_o = 24'sd8326936;  sin_o = -24'sd1844954; end
            8'd10:  begin cos_o = 24'sd8312266;  sin_o = -24'sd2047852; end
            8'd11:  begin cos_o = 24'sd8296038;  sin_o = -24'sd2250095; end
            8'd12:  begin cos_o = 24'sd8278255;  sin_o = -24'sd2451621; end
            8'd13:  begin cos_o = 24'sd8258920;  sin_o = -24'sd2652364; end
            8'd14:  begin cos_o = 24'sd8238034;  sin_o = -24'sd2852264; end
            8'd15:  begin cos_o = 24'sd8215602;  sin_o = -24'sd3051259; end
            8'd16:  begin cos_o = 24'sd8191627;  sin_o = -24'sd3249288; end
            8'd17:  begin cos_o = 24'sd8166111;  sin_o = -24'sd3446291; end
            8'd18:  begin cos_o = 24'sd8139059;  sin_o = -24'sd3642207; end
            8'd19:  begin cos_o = 24'sd8110475;  sin_o = -24'sd3836977; end
            8'd20:  begin cos_o = 24'sd8080361;  sin_o = -24'sd4030540; end
            8'd21:  begin cos_o = 24'sd8048724;  sin_o = -24'sd4222838; end
            8'd22:  begin cos_o = 24'sd8015567;  sin_o = -24'sd4413811; end
            8'd23:  begin cos_o = 24'sd7980896;  sin_o = -24'sd4603401; end
            8'd24:  begin cos_o = 24'sd7944716;  sin_o = -24'sd4791551; end
            8'd25:  begin cos_o = 24'sd7907033;  sin_o = -24'sd4978202; end
            8'd26:  begin cos_o = 24'sd7867852;  sin_o = -24'sd5163298; end
            8'd27:  begin cos_o = 24'sd7827181;  sin_o = -24'sd5346783; end
            8'd28:  begin cos_o = 24'sd7785026;  sin_o = -24'sd5528600; end
            8'd29:  begin cos_o = 24'sd7741394;  sin_o = -24'sd5708694; end
            8'd30:  begin cos_o = 24'sd7696293;  sin_o = -24'sd5887009; end
            8'd31:  begin cos_o = 24'sd7649730;  sin_o = -24'sd6063492; end
            8'd32:  begin cos_o = 24'sd7601713;  sin_o = -24'sd6238087; end
            8'd33:  begin cos_o = 24'sd7552248;  sin_o = -24'sd6410741; end
            8'd34:  begin cos_o = 24'sd7501345;  sin_o = -24'sd6581401; end
            8'd35:  begin cos_o = 24'sd7449011;  sin_o = -24'sd6750013; end
            8'd36:  begin cos_o = 24'sd7395254;  sin_o = -24'sd6916525; end
            8'd37:  begin cos_o = 24'sd7340084;  sin_o = -24'sd7080885; end
            8'd38:  begin cos_o = 24'sd7283509;  sin_o = -24'sd7243041; end
            8'd39:  begin cos_o = 24'sd7225539;  sin_o = -24'sd7402943; end
            8'd40:  begin cos_o = 24'sd7166182;  sin_o = -24'sd7560539; end
            8'd41:  begin cos_o = 24'sd7105450;  sin_o = -24'sd7715779; end
            8'd42:  begin cos_o = 24'sd7043352;  sin_o = -24'sd7868613; end
            8'd43:  begin cos_o = 24'sd6979898;  sin_o = -24'sd8018992; end
            8'd44:  begin cos_o = 24'sd6915099;  sin_o = -24'sd8166866; end
            8'd45:  begin cos_o = 24'sd6848965;  sin_o = -24'sd8312187; end
            8'd46:  begin cos_o = 24'sd6781506;  sin_o = -24'sd8454907; end
            8'd47:  begin cos_o = 24'sd6712733;  sin_o = -24'sd8594978; end
            8'd48:  begin cos_o = 24'sd6642657;  sin_o = -24'sd8732352; end
            8'd49:  begin cos_o = 24'sd6571288;  sin_o = -24'sd8866983; end
            8'd50:  begin cos_o = 24'sd6498638;  sin_o = -24'sd8998825; end
            8'd51:  begin cos_o = 24'sd6424719;  sin_o = -24'sd9127832; end
            8'd52:  begin cos_o = 24'sd6349541;  sin_o = -24'sd9253959; end
            8'd53:  begin cos_o = 24'sd6273117;  sin_o = -24'sd9377162; end
            8'd54:  begin cos_o = 24'sd6195458;  sin_o = -24'sd9497397; end
            8'd55:  begin cos_o = 24'sd6116576;  sin_o = -24'sd9614620; end
            8'd56:  begin cos_o = 24'sd6036483;  sin_o = -24'sd9728789; end
            8'd57:  begin cos_o = 24'sd5955191;  sin_o = -24'sd9839862; end
            8'd58:  begin cos_o = 24'sd5872713;  sin_o = -24'sd9947797; end
            8'd59:  begin cos_o = 24'sd5789060;  sin_o = -24'sd10052553; end
            8'd60:  begin cos_o = 24'sd5704246;  sin_o = -24'sd10154089; end
            8'd61:  begin cos_o = 24'sd5618283;  sin_o = -24'sd10252366; end
            8'd62:  begin cos_o = 24'sd5531183;  sin_o = -24'sd10347344; end
            8'd63:  begin cos_o = 24'sd5442960;  sin_o = -24'sd10438985; end
            8'd64:  begin cos_o = 24'sd5353627;  sin_o = -24'sd10527250; end
            8'd65:  begin cos_o = 24'sd5263197;  sin_o = -24'sd10612103; end
            8'd66:  begin cos_o = 24'sd5171683;  sin_o = -24'sd10693505; end
            8'd67:  begin cos_o = 24'sd5079099;  sin_o = -24'sd10771423; end
            8'd68:  begin cos_o = 24'sd4985459;  sin_o = -24'sd10845821; end
            8'd69:  begin cos_o = 24'sd4890776;  sin_o = -24'sd10916665; end
            8'd70:  begin cos_o = 24'sd4795064;  sin_o = -24'sd10983920; end
            8'd71:  begin cos_o = 24'sd4698337;  sin_o = -24'sd11047556; end
            8'd72:  begin cos_o = 24'sd4600610;  sin_o = -24'sd11107538; end
            8'd73:  begin cos_o = 24'sd4501897;  sin_o = -24'sd11163837; end
            8'd74:  begin cos_o = 24'sd4402211;  sin_o = -24'sd11216421; end
            8'd75:  begin cos_o = 24'sd4301569;  sin_o = -24'sd11265259; end
            8'd76:  begin cos_o = 24'sd4199984;  sin_o = -24'sd11310322; end
            8'd77:  begin cos_o = 24'sd4097472;  sin_o = -24'sd11351582; end
            8'd78:  begin cos_o = 24'sd3994047;  sin_o = -24'sd11389010; end
            8'd79:  begin cos_o = 24'sd3889725;  sin_o = -24'sd11422580; end
            8'd80:  begin cos_o = 24'sd3784520;  sin_o = -24'sd11452263; end
            8'd81:  begin cos_o = 24'sd3678448;  sin_o = -24'sd11478034; end
            8'd82:  begin cos_o = 24'sd3571524;  sin_o = -24'sd11499868; end
            8'd83:  begin cos_o = 24'sd3463764;  sin_o = -24'sd11517740; end
            8'd84:  begin cos_o = 24'sd3355184;  sin_o = -24'sd11531625; end
            8'd85:  begin cos_o = 24'sd3245799;  sin_o = -24'sd11541501; end
            8'd86:  begin cos_o = 24'sd3135625;  sin_o = -24'sd11547344; end
            8'd87:  begin cos_o = 24'sd3024678;  sin_o = -24'sd11549132; end
            8'd88:  begin cos_o = 24'sd2912975;  sin_o = -24'sd11546843; end
            8'd89:  begin cos_o = 24'sd2800531;  sin_o = -24'sd11540456; end
            8'd90:  begin cos_o = 24'sd2687362;  sin_o = -24'sd11529952; end
            8'd91:  begin cos_o = 24'sd2573486;  sin_o = -24'sd11515311; end
            8'd92:  begin cos_o = 24'sd2458918;  sin_o = -24'sd11496515; end
            8'd93:  begin cos_o = 24'sd2343675;  sin_o = -24'sd11473547; end
            8'd94:  begin cos_o = 24'sd2227775;  sin_o = -24'sd11446389; end
            8'd95:  begin cos_o = 24'sd2111233;  sin_o = -24'sd11415026; end
            8'd96:  begin cos_o = 24'sd1994068;  sin_o = -24'sd11379443; end
            8'd97:  begin cos_o = 24'sd1876296;  sin_o = -24'sd11339625; end
            8'd98:  begin cos_o = 24'sd1757935;  sin_o = -24'sd11295558; end
            8'd99:  begin cos_o = 24'sd1639002;  sin_o = -24'sd11247230; end
            8'd100: begin cos_o = 24'sd1519514;  sin_o = -24'sd11194627; end
            8'd101: begin cos_o = 24'sd1399489;  sin_o = -24'sd11137738; end
            8'd102: begin cos_o = 24'sd1278944;  sin_o = -24'sd11076552; end
            8'd103: begin cos_o = 24'sd1157897;  sin_o = -24'sd11011058; end
            8'd104: begin cos_o = 24'sd1036365;  sin_o = -24'sd10941246; end
            8'd105: begin cos_o = 24'sd914367;   sin_o = -24'sd10867107; end
            8'd106: begin cos_o = 24'sd791919;   sin_o = -24'sd10788632; end
            8'd107: begin cos_o = 24'sd669041;   sin_o = -24'sd10705813; end
            8'd108: begin cos_o = 24'sd545749;   sin_o = -24'sd10618641; end
            8'd109: begin cos_o = 24'sd422062;   sin_o = -24'sd10527110; end
            8'd110: begin cos_o = 24'sd297998;   sin_o = -24'sd10431213; end
            8'd111: begin cos_o = 24'sd173575;   sin_o = -24'sd10330943; end
            8'd112: begin cos_o = 24'sd48811;    sin_o = -24'sd10226296; end
            8'd113: begin cos_o = -24'sd76283;   sin_o = -24'sd10117265; end
            8'd114: begin cos_o = -24'sd201687;  sin_o = -24'sd10003847; end
            8'd115: begin cos_o = -24'sd327382;  sin_o = -24'sd9886038; end
            8'd116: begin cos_o = -24'sd453348;  sin_o = -24'sd9763836; end
            8'd117: begin cos_o = -24'sd579566;  sin_o = -24'sd9637239; end
            8'd118: begin cos_o = -24'sd706017;  sin_o = -24'sd9506247; end
            8'd119: begin cos_o = -24'sd832682;  sin_o = -24'sd9370859; end
            8'd120: begin cos_o = -24'sd959542;  sin_o = -24'sd9231077; end
            8'd121: begin cos_o = -24'sd1086579; sin_o = -24'sd9086903; end
            8'd122: begin cos_o = -24'sd1213773; sin_o = -24'sd8938340; end
            8'd123: begin cos_o = -24'sd1341107; sin_o = -24'sd8785391; end
            8'd124: begin cos_o = -24'sd1468561; sin_o = -24'sd8628061; end
            8'd125: begin cos_o = -24'sd1596118; sin_o = -24'sd8466355; end
            8'd126: begin cos_o = -24'sd1723758; sin_o = -24'sd8300279; end
            8'd127: begin cos_o = -24'sd1851464; sin_o = -24'sd8129840; end
            8'd128: begin cos_o = -24'sd1979217; sin_o = -24'sd7955046; end
            8'd129: begin cos_o = -24'sd2107000; sin_o = -24'sd7775905; end
            8'd130: begin cos_o = -24'sd2234794; sin_o = -24'sd7592427; end
            8'd131: begin cos_o = -24'sd2362581; sin_o = -24'sd7404622; end
            8'd132: begin cos_o = -24'sd2490343; sin_o = -24'sd7212500; end
            8'd133: begin cos_o = -24'sd2618063; sin_o = -24'sd7016074; end
            8'd134: begin cos_o = -24'sd2745722; sin_o = -24'sd6815355; end
            8'd135: begin cos_o = -24'sd2873303; sin_o = -24'sd6610356; end
            8'd136: begin cos_o = -24'sd3000788; sin_o = -24'sd6401092; end
            8'd137: begin cos_o = -24'sd3128159; sin_o = -24'sd6187575; end
            8'd138: begin cos_o = -24'sd3255398; sin_o = -24'sd5969822; end
            8'd139: begin cos_o = -24'sd3382489; sin_o = -24'sd5747847; end
            8'd140: begin cos_o = -24'sd3509413; sin_o = -24'sd5521667; end
            8'd141: begin cos_o = -24'sd3636153; sin_o = -24'sd5291300; end
            8'd142: begin cos_o = -24'sd3762692; sin_o = -24'sd5056763; end
            8'd143: begin cos_o = -24'sd3889012; sin_o = -24'sd4818075; end
            8'd144: begin cos_o = -24'sd4015097; sin_o = -24'sd4575255; end
            8'd145: begin cos_o = -24'sd4140928; sin_o = -24'sd4328323; end
            8'd146: begin cos_o = -24'sd4266489; sin_o = -24'sd4077299; end
            8'd147: begin cos_o = -24'sd4391763; sin_o = -24'sd3822204; end
            8'd148: begin cos_o = -24'sd4516732; sin_o = -24'sd3563060; end
            8'd149: begin cos_o = -24'sd4641379; sin_o = -24'sd3299888; end
            8'd150: begin cos_o = -24'sd4765688; sin_o = -24'sd3032710; end
            8'd151: begin cos_o = -24'sd4889641; sin_o = -24'sd2761550; end
            8'd152: begin cos_o = -24'sd5013222; sin_o = -24'sd2486431; end
            8'd153: begin cos_o = -24'sd5136414; sin_o = -24'sd2207378; end
            8'd154: begin cos_o = -24'sd5259200; sin_o = -24'sd1924414; end
            8'd155: begin cos_o = -24'sd5381564; sin_o = -24'sd1637565; end
            8'd156: begin cos_o = -24'sd5503489; sin_o = -24'sd1346854; end
            8'd157: begin cos_o = -24'sd5624959; sin_o = -24'sd1052308; end
            8'd158: begin cos_o = -24'sd5745958; sin_o = -24'sd753952; end
            8'd159: begin cos_o = -24'sd5866469; sin_o = -24'sd451813; end
            8'd160: begin cos_o = -24'sd5986476; sin_o = -24'sd145917; end
            8'd161: begin cos_o = -24'sd6105963; sin_o = 24'sd163709; end
            8'd162: begin cos_o = -24'sd6224914; sin_o = 24'sd477032; end
            8'd163: begin cos_o = -24'sd6343313; sin_o = 24'sd794028; end
            8'd164: begin cos_o = -24'sd6461143; sin_o = 24'sd1114670; end
            8'd165: begin cos_o = -24'sd6578390; sin_o = 24'sd1438931; end
            8'd166: begin cos_o = -24'sd6695037; sin_o = 24'sd1766783; end
            8'd167: begin cos_o = -24'sd6811069; sin_o = 24'sd2098200; end
            8'd168: begin cos_o = -24'sd6926470; sin_o = 24'sd2433154; end
            8'd169: begin cos_o = -24'sd7041225; sin_o = 24'sd2771618; end
            8'd170: begin cos_o = -24'sd7155318; sin_o = 24'sd3113565; end
            8'd171: begin cos_o = -24'sd7268734; sin_o = 24'sd3458967; end
            8'd172: begin cos_o = -24'sd7381457; sin_o = 24'sd3807799; end
            8'd173: begin cos_o = -24'sd7493473; sin_o = 24'sd4160031; end
            8'd174: begin cos_o = -24'sd7604766; sin_o = 24'sd4515638; end
            8'd175: begin cos_o = -24'sd7715320; sin_o = 24'sd4874591; end
            8'd176: begin cos_o = -24'sd7825121; sin_o = 24'sd5236863; end
            8'd177: begin cos_o = -24'sd7934154; sin_o = 24'sd5602426; end
            8'd178: begin cos_o = -24'sd8042404; sin_o = 24'sd5971253; end
            8'd179: begin cos_o = -24'sd8149855; sin_o = 24'sd6343315; end
            8'd180: begin cos_o = -24'sd8256493; sin_o = 24'sd6718585; end
            8'd181: begin cos_o = -24'sd8362303; sin_o = 24'sd7097035; end
            8'd182: begin cos_o = -24'sd8467271; sin_o = 24'sd7478637; end
            8'd183: begin cos_o = -24'sd8571381; sin_o = 24'sd7863364; end
            8'd184: begin cos_o = -24'sd8674620; sin_o = 24'sd8251186; end
            8'd185: begin cos_o = -24'sd8776973; sin_o = 24'sd8642076; end
            8'd186: begin cos_o = -24'sd8878426; sin_o = 24'sd9036006; end
            8'd187: begin cos_o = -24'sd8978964; sin_o = 24'sd9432946; end
            8'd188: begin cos_o = -24'sd9078574; sin_o = 24'sd9832869; end
            8'd189: begin cos_o = -24'sd9177242; sin_o = 24'sd10235746; end
            8'd190: begin cos_o = -24'sd9274954; sin_o = 24'sd10641549; end
            8'd191: begin cos_o = -24'sd9371696; sin_o = 24'sd11050249; end
            8'd192: begin cos_o = -24'sd9467454; sin_o = 24'sd11461819; end
            8'd193: begin cos_o = -24'sd9562215; sin_o = 24'sd11876230; end
            8'd194: begin cos_o = -24'sd9655965; sin_o = 24'sd12293453; end
            8'd195: begin cos_o = -24'sd9748691; sin_o = 24'sd12713461; end
            8'd196: begin cos_o = -24'sd9840379; sin_o = 24'sd13136224; end
            8'd197: begin cos_o = -24'sd9931016; sin_o = 24'sd13561714; end
            8'd198: begin cos_o = -24'sd10020588; sin_o = 24'sd13989903; end
            8'd199: begin cos_o = -24'sd10109082; sin_o = 24'sd14420761; end
            8'd200: begin cos_o = -24'sd10196485; sin_o = 24'sd14854260; end
            8'd201: begin cos_o = -24'sd10282783; sin_o = 24'sd15290372; end
            8'd202: begin cos_o = -24'sd10367964; sin_o = 24'sd15729066; end
            8'd203: begin cos_o = -24'sd10452015; sin_o = 24'sd16170316; end
            8'd204: begin cos_o = -24'sd10534924; sin_o = 24'sd16614091; end
            8'd205: begin cos_o = -24'sd10616677; sin_o = 24'sd17060364; end
            8'd206: begin cos_o = -24'sd10697263; sin_o = 24'sd17509105; end
            8'd207: begin cos_o = -24'sd10776669; sin_o = 24'sd17960284; end
            8'd208: begin cos_o = -24'sd10854883; sin_o = 24'sd18413873; end
            8'd209: begin cos_o = -24'sd10931893; sin_o = 24'sd18869842; end
            8'd210: begin cos_o = -24'sd11007686; sin_o = 24'sd19328162; end
            8'd211: begin cos_o = -24'sd11082251; sin_o = 24'sd19788802; end
            8'd212: begin cos_o = -24'sd11155577; sin_o = 24'sd20251733; end
            8'd213: begin cos_o = -24'sd11227650; sin_o = 24'sd20716925; end
            8'd214: begin cos_o = -24'sd11298461; sin_o = 24'sd21184348; end
            8'd215: begin cos_o = -24'sd11367996; sin_o = 24'sd21653971; end
            8'd216: begin cos_o = -24'sd11436246; sin_o = 24'sd22125764; end
            8'd217: begin cos_o = -24'sd11503198; sin_o = 24'sd22599696; end
            8'd218: begin cos_o = -24'sd11568842; sin_o = 24'sd23075737; end
            8'd219: begin cos_o = -24'sd11633166; sin_o = 24'sd23553855; end
            8'd220: begin cos_o = -24'sd11696160; sin_o = 24'sd24034019; end
            8'd221: begin cos_o = -24'sd11757812; sin_o = 24'sd24516199; end
            8'd222: begin cos_o = -24'sd11818111; sin_o = 24'sd25000362; end
            8'd223: begin cos_o = -24'sd11877046; sin_o = 24'sd25486477; end
            8'd224: begin cos_o = -24'sd11934607; sin_o = 24'sd25974512; end
            8'd225: begin cos_o = -24'sd11990782; sin_o = 24'sd26464436; end
            8'd226: begin cos_o = -24'sd12045560; sin_o = 24'sd26956217; end
            8'd227: begin cos_o = -24'sd12098933; sin_o = 24'sd27449822; end
            8'd228: begin cos_o = -24'sd12150889; sin_o = 24'sd27945220; end
            8'd229: begin cos_o = -24'sd12201418; sin_o = 24'sd28442378; end
            8'd230: begin cos_o = -24'sd12250510; sin_o = 24'sd28941263; end
            8'd231: begin cos_o = -24'sd12298154; sin_o = 24'sd29441843; end
            8'd232: begin cos_o = -24'sd12344340; sin_o = 24'sd29944084; end
            8'd233: begin cos_o = -24'sd12389057; sin_o = 24'sd30447954; end
            8'd234: begin cos_o = -24'sd12432296; sin_o = 24'sd30953420; end
            8'd235: begin cos_o = -24'sd12474045; sin_o = 24'sd31460449; end
            8'd236: begin cos_o = -24'sd12514295; sin_o = 24'sd31969008; end
            8'd237: begin cos_o = -24'sd12553036; sin_o = 24'sd32479064; end
            8'd238: begin cos_o = -24'sd12590257; sin_o = 24'sd32990583; end
            8'd239: begin cos_o = -24'sd12625949; sin_o = 24'sd33503532; end
            8'd240: begin cos_o = -24'sd12660102; sin_o = 24'sd34017878; end
            8'd241: begin cos_o = -24'sd12692706; sin_o = 24'sd34533587; end
            8'd242: begin cos_o = -24'sd12723752; sin_o = 24'sd35050626; end
            8'd243: begin cos_o = -24'sd12753230; sin_o = 24'sd35568961; end
            8'd244: begin cos_o = -24'sd12781131; sin_o = 24'sd36088559; end
            8'd245: begin cos_o = -24'sd12807445; sin_o = 24'sd36609386; end
            8'd246: begin cos_o = -24'sd12832162; sin_o = 24'sd37131408; end
            8'd247: begin cos_o = -24'sd12855274; sin_o = 24'sd37654591; end
            8'd248: begin cos_o = -24'sd12876771; sin_o = 24'sd38178901; end
            8'd249: begin cos_o = -24'sd12896644; sin_o = 24'sd38704304; end
            8'd250: begin cos_o = -24'sd12914884; sin_o = 24'sd39230766; end
            8'd251: begin cos_o = -24'sd12931483; sin_o = 24'sd39758252; end
            8'd252: begin cos_o = -24'sd12946431; sin_o = 24'sd40286730; end
            8'd253: begin cos_o = -24'sd12959719; sin_o = 24'sd40816164; end
            8'd254: begin cos_o = -24'sd12971339; sin_o = 24'sd41346521; end
            8'd255: begin cos_o = -24'sd12981282; sin_o = 24'sd41877766; end
        endcase
    end

endmodule
