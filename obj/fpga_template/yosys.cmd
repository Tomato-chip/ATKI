#Yosys build script
verilog_defaults -add -I /home/tomato-chip/ATKI/digital
read_verilog  /home/tomato-chip/ATKI/digital/Project_files/i2s_capture_24_test.sv.conv.v /home/tomato-chip/ATKI/digital/Project_files/i2s_clock_gen_test.sv.conv.v /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv.conv.v /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv.conv.v /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv.conv.v /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv.conv.v
synth_gowin -top fpga_template_top -json /home/tomato-chip/ATKI/obj/fpga_template/fpga_template.json
