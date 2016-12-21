/* 
 * File:   main.c
 * Author: robert
 *
 * Created on 29 de diciembre de 2014, 06:04 PM
 */
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "../../LIBRARY_LABOTEC/system.h"
#include <libpic30.h>
#include "../../LIBRARY_LABOTEC/lcd.h"
#include "../../LIBRARY_LABOTEC/adc.h"

int main(){

    int var=0;
    init_register();
    LCDinit();
    InitADC();
    TRISB=0;
    while(1){
        var=ReadADC();
        LATB=var;
        LCDGotoXY(2,1);
        LCDsend_var(var);
        __delay_ms(300);
        LCDsendCommand(CLEAR_DISPLAY );
    }

    return 0;
}

