/*
 * File:   main.c
 * Author: robert
 *
 * Created on 29 de diciembre de 2014, 12:50 PM
 */
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#define FCY             40000000UL
#include <libpic30.h>
//  FNOSC_FRC  -> Internal Fast RC (FRC)
_FOSCSEL(FNOSC_FRC);
//  FCKSM_CSECMD -> Clock switching is enabled,
//                  Fail-Safe Clock Monitor is disabled
//  OSCIOFNC_OFF -> OSC2 pin has clock out function
_FOSC(FCKSM_CSECMD & OSCIOFNC_OFF);

int main(int argc, char** argv){
    PLLFBD=43;                  // M  = 43
    CLKDIVbits.PLLPRE=0;        // N1 = 2
    CLKDIVbits.PLLPOST=0;       // N2 = 2

    __builtin_write_OSCCONH(0x01);  //  001 = Fast RC oscillator (FRC) with PLL
    __builtin_write_OSCCONL(0x01);  //  Request oscillator switch to selection
                                    //  specified by NOSC<2:0> bits
    // Wait for clock switch to occur
    while (OSCCONbits.COSC != 0b001){ }
    // Wait for PLL to lock
    while(OSCCONbits.LOCK !=1) {}

    TRISAbits.TRISA7=1; //  Setup as Input
    TRISAbits.TRISA8=0; //  Setup as Output

    for(;;){

        if(PORTAbits.RA7==1) LATAbits.LATA8=1;
        else LATAbits.LATA8=0;
    }

    return (EXIT_SUCCESS);
}



