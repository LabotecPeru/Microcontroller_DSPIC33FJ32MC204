/*
 * File:   main.c
 * Author: robert
 *
 * Created on 29 de diciembre de 2014, 03:52 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "../../LIBRARY_LABOTEC/system.h"
#include <libpic30.h>
#include "../../LIBRARY_LABOTEC/lcd.h"
#include "../../LIBRARY_LABOTEC/keypad.h"

int main(){

    unsigned char data1[]="LABOTEC";
    int i;

    init_register();
    LCDinit();
    keypad_init();

    LCDsendCommand(CLEAR_DISPLAY);      //  limpia pantalla
    LCDGotoXY(0,0);			//  posicion en la direccion (4,0)
    LCDstring(data1,sizeof(data1));	//  envio una cadena al LCD

    for(;;){
        LCDGotoXY(0,0);
        LCDstring("LABOTEC",7);
        LCDGotoXY(0,1);
        LCDsend_var(i++);
        __delay_ms(300);
        LCDsendCommand(CLEAR_DISPLAY);
         
    }

    return 0;
}



