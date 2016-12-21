/*
 * File:   main.c
 * Author: robert
 *
 * Created on 29 de diciembre de 2014, 12:50 PM
 */
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "../../LIBRARY_LABOTEC/system.h"
#include <libpic30.h>
#include "../../LIBRARY_LABOTEC/uart.h"

int main(int argc, char** argv) {

    init_register();
    init_uart_polling(9600);

    for(;;){
        usart_puts("HELLO LABOTEC\r\n");
        __delay_ms(100);
    }

     return (EXIT_SUCCESS);
}




