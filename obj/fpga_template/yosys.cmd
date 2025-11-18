#Yosys build script
verilog_defaults -add -I /home/tomato-chip/ATKI/digital
read_verilog /home/tomato-chip/ATKI/digital/uart_if/uart_if.v /home/tomato-chip/ATKI/digital/fpga_template/build/i2s_clock_gen.sv.conv.v /home/tomato-chip/ATKI/digital/fpga_template/build/i2s_capture_24.sv.conv.v /home/tomato-chip/ATKI/digital/fpga_template/build/vu_meter_6led.sv.conv.v /home/tomato-chip/ATKI/digital/fpga_template/build/rb_fpga_template.sv.conv.v /home/tomato-chip/ATKI/digital/fpga_template/build/fpga_template_interface_module.sv.conv.v /home/tomato-chip/ATKI/digital/fpga_template/build/fpga_template.sv.conv.v
synth_gowin -top fpga_template_top -json /home/tomato-chip/ATKI/obj/fpga_template/fpga_template.json
