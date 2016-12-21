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
    char k=0;
    int dato;

    init_register();
    LCDinit();
    keypad_init();

    LCDsendCommand(CLEAR_DISPLAY);      //  limpia pantalla
    LCDGotoXY(0,0);			//  posicion en la direccion (4,0)
    LCDstring(data1,sizeof(data1));	//  envio una cadena al LCD

    for(;;){

         k=keypad_getc();  
         dato=k-48;        

         if(k!=0 && k!='A' && k!='B' && k!='C' && k!='D' && k!='*' && k!='#'){
            LCDsendCommand(CLEAR_DISPLAY);
            LCDGotoXY(0,0);			
            LCDstring(data1,sizeof(data1));	
            LCDGotoXY(0,1);
            LCDstring("Dato=",5);
            LCDGotoXY(5,1);
            LCDsend_var(dato);
            __delay_ms(30);
         }
    }

    return 0;
}



