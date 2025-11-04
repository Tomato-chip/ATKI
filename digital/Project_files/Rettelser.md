write_address for lille ?

buffer_overflow_o er ligegyldig


De her skal samles!!
husk ADDR_WIDTH og ADDR_WIDTH-1 !!!!!

    logic [ADDR_WIDTH-1:0]  write_address;
    logic [ADDR_WIDTH-1:0]  read_address;

    logic [ADDR_WIDTH:0]    write_count;
    logic [ADDR_WIDTH:0]    read_count;



read_buffer_valid er altid 1





!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

Problemet ligger i ram read out! og i VU der bliver ved med at hente data, efter 16 samples er beregnet.
Sæt tiden ned på VU. og sørg for at den ikke bliver ved med at hente data fra ram, når der ikke er mere.
Lad den eventuelt læse langsommere, eller gemme værdien på led.
