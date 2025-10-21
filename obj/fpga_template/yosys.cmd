#Yosys build script
verilog_defaults -add -I /home/tomato-chip/fpga_template/digital
read_verilog /home/tomato-chip/fpga_template/digital/pwm/pwm.v /home/tomato-chip/fpga_template/digital/i2c_if/i2c_if.v /home/tomato-chip/fpga_template/digital/i2c_if/i2cSlave_define.v /home/tomato-chip/fpga_template/digital/i2c_if/serialInterface.v /home/tomato-chip/fpga_template/digital/i2c_if/timescale.v /home/tomato-chip/fpga_template/digital/uart_if/uart_if.v /home/tomato-chip/fpga_template/digital/rb_fpga_template/rb_fpga_template.sv.conv.v /home/tomato-chip/fpga_template/digital/fpga_template/fpga_template.sv.conv.v
synth_gowin -top fpga_template_top -json /home/tomato-chip/fpga_template/obj/fpga_template/fpga_template.json
