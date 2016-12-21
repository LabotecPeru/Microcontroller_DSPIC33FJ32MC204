#include <xc.h>
#include "system.h"
#include "uart.h"

void init_uart_polling(long BaudRate){
    RPOR10bits.RP20R  = 3;      // TX is on RP20
    RPINR18bits.U1RXR = 21;     // RX is on RP21

    U1MODEbits.UARTEN   = UART_ENABLED;
    U1MODEbits.USIDL    = UART_CONTINUE_IDLE_MODE;
    U1MODEbits.IREN     = UART_ENC_DEC_DISABLED ;

    U1MODEbits.RTSMD    = UART_SIMPLEX_MODE;
    U1MODEbits.UEN      = UART_U1XT_U1RX_ENABLED;
    U1MODEbits.WAKE     = UART_LOOPBACK_ENABLED;
    U1MODEbits.LPBACK   = UART_LOOPBACK_DISABLED;
    U1MODEbits.URXINV   = UART_U1RX_IDLE_STATE_ONE;
    U1MODEbits.BRGH     = UART_16CLOCKS_PER_BIT ;
    U1MODEbits.PDSEL    = UART_8DATA_BITS_NO_PARITY;
    U1MODEbits.STSEL    = UART_ONE_STOPS_BITS;

    U1STAbits.UTXINV    = UART_U1TX_IDLE_STATE_ONE;
    U1STAbits.UTXBRK    = UART_SYNC_BREAK_DISABLED;
    U1STAbits.UTXEN     = UART_TRANSMIT_ENABLED;
    U1STAbits.ADDEN     = UART_DETECT_MODE_DISABLED;

    U1BRG=(FCY/(16*(BaudRate)))-1;

}

void envia_caracter(unsigned char data) {

   U1TXREG = data;
   while(U1STAbits.TRMT==0){
   }
}

void usart_puts(char* data) {
   while (*data)
      envia_caracter(*(data++));
}