#include <xc.h>
#include "system.h"

_FOSCSEL(FNOSC_FRC);    
_FOSC(FCKSM_CSECMD & OSCIOFNC_ON);
_FICD(JTAGEN_OFF)

void init_register(void){

    AD1PCFGL=0xFFF;     //  Configura los canales analogicos como I/O Digital

    PLLFBD=43;              //  M = 43
    CLKDIVbits.PLLPRE=0;    //  N1 = 2
    CLKDIVbits.PLLPOST=0;   //  N2 = 2

    __builtin_write_OSCCONH(0x01);
    __builtin_write_OSCCONL(0x01);
    // Wait for clock switch to occur
    while (OSCCONbits.COSC != 0b001){ }
    // Wait for PLL to lock
    while(OSCCONbits.LOCK !=1) {}

}