// ============================================================================
// generate_pcm_hex.c
// Genererer en dummy 24-bit PCM-sine og gemmer den som hex-værdier i en fil.
//
// Filformat:
//  - Tekstfil
//  - Én sample pr. linje
//  - Hver sample er 24-bit to's complement, skrevet som 6 hex-tegn (0..F)
//    fx: 000000, 7FFFFF, 800000, FFFFFF
//
// Formål:
//  - Kan bruges med Verilog $readmemh("pcm_data.hex", mem);
//  - Perfekt til at fodre dine DSP/FFT/VU-moduler i simulation.
//
// Kørsel (fra terminal i projektets rodmappe):
//  1) cd tools
//  2) gcc generate_pcm_hex.c -o generate_pcm_hex -lm
//  3) ./generate_pcm_hex
// ============================================================================

#include <stdio.h>    // printf, FILE, fopen, fprintf, fclose
#include <stdint.h>   // faste integer-typer som int32_t, uint32_t
#include <math.h>     // sin(), M_PI (på nogle systemer) - vi definerer selv PI

// --------------------------------------------------------------------------
// Konstanter for signalet
// --------------------------------------------------------------------------
#define NUM_SAMPLES 256              // Antal samples vi vil generere
#define SAMPLE_RATE 48000.0           // Samplerate i Hz (kun til frekvensberegning)
#define TONE_FREQ   1000.0            // Frekvens på sinus i Hz
#define PI          3.141592653589793 // Pi-konstant

int main(void)                        // main-funktion, programmet starter her
{
    // ----------------------------------------------------------------------
    // 1) Vælg hvor filen skal gemmes
    // ----------------------------------------------------------------------
    // Vi gemmer filen i ../sim/pcm_data.hex ift. tools/-mappen.
    //  - "../" betyder: én mappe op (fra tools/ til projekt-roden)
    //  - "sim/" er mappen til simulationsfiler
    //  - "pcm_data.hex" er selve filnavnet
    // Hvis du ikke har en sim/-mappe, så lav den, eller ændr stien til "pcm_data.hex".
    // ----------------------------------------------------------------------
    const char *filename = "pcm_data.hex";

    // Åbn filen til skrivning ("w" = write, overskriver hvis den findes)
    FILE *f = fopen(filename, "w");
    if (f == NULL)                    // Tjek om fopen fejlede (fx hvis mappen ikke findes)
    {
        printf("Fejl: kunne ikke åbne filen %s til skrivning.\n", filename);
        return 1;                     // Afslut program med fejl-kode 1
    }

    // ----------------------------------------------------------------------
    // 2) Beregn amplitude for 24-bit signed
    // ----------------------------------------------------------------------
    // 24-bit signed to's complement har range:
    //  - Minimum: -2^23
    //  - Maksimum:  2^23 - 1
    //
    // Vi bruger 80% af fuld skala for at undgå at ramme præcis ±FS.
    // ----------------------------------------------------------------------
    double amplitude = 0.8 * (double)((1 << 23) - 1);

    // ----------------------------------------------------------------------
    // 3) Generér samples én for én
    // ----------------------------------------------------------------------
    for (int n = 0; n < NUM_SAMPLES; n++)
    {
        // Tid i sekunder for sample n
        double t = (double)n / SAMPLE_RATE;

        // Sinusværdi mellem -1.0 og +1.0
        double s = sin(2.0 * PI * TONE_FREQ * t);

        // Skalér sinus til 24-bit signed heltal (men gemt i 32-bit variabel)
        int32_t sample = (int32_t)(amplitude * s);

        // Maskér ned til 24 lowest bits (to's complement format)
        //  - Hvis sample er negativ, vil de øverste bits i 32-bit være 1
        //  - Maskning med 0xFFFFFF sørger for at vi kun skriver de nederste 24 bits
        uint32_t word24 = (uint32_t)sample & 0xFFFFFFu;

        // Skriv sample som 6-cifret hex (24-bit) efterfulgt af newline
        // "%06X" betyder:
        //  - %X  : print som hex med store bogstaver (A..F)
        //  - 06  : udfyld med 0'er så bredden altid er 6 tegn
        fprintf(f, "%06X\n", word24);
    }

    // ----------------------------------------------------------------------
    // 4) Luk filen og afslut
    // ----------------------------------------------------------------------
    fclose(f);                        // Sørg for at alt bliver skrevet til disk

    // Info til terminalen
    printf("OK: %d samples skrevet til %s\n", NUM_SAMPLES, filename);

    return 0;                         // Afslut program uden fejl
}
