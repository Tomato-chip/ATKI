





### i2s_clock_gen.sv / i2s_clock_gen.md

Der er problemer med frames for at få den korrekte ws frekvens.
Der skal gerne stå 64 men så fås en frekvens på 26.4 kHz.
    `Linje 28 i i2s_clock_gen.md`
    `Linje 17 i i2s_clock_gen.sv`

  parameter int unsigned SCKS_PER_FRAME  = 32,          // SCKs per full frame (L+R)

Der skal kun være en værdi for half frame da det altid er 50% duty cycle:
    // SCK generation - 50% duty cycle
  localparam int unsigned SCK_HALF_HIGH = SCK_DIV / 2;
  localparam int unsigned SCK_HALF_LOW  = SCK_DIV - SCK_HALF_HIGH;