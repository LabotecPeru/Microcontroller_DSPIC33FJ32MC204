/* 
 * File:   uart.h
 * Author: robert
 *
 * Created on 30 de diciembre de 2014, 10:39
 */

#ifndef UART_H
#define	UART_H

/*	R E G I S T E R - U 1 M O D E       */
/*  UARTEN: UARTx Enable bit        */
#define UART_ENABLED                    1
#define UART_DISABLED			0
/*  USIDL: Stop in Idle Mode bit    */
#define UART_DISCONTINUE_IDLE_MODE	1
#define UART_CONTINUE_IDLE_MODE		0
/*  IREN: IrDA Encoder and Decoder Enable bit      */
#define UART_ENC_DEC_ENABLED            1
#define UART_ENC_DEC_DISABLED           0
/*  RTSMD: Mode Selection for UxRTS Pin bit      */
#define UART_SIMPLEX_MODE		1
#define UART_FLOW_CONTROL_MODE		0
/*  UEN<1:0>: UARTx Enable bits     */
#define UART_U1XT_U1RX_BCLK_ENABLED		3
#define UART_U1XT_U1RX_U1CTS_U1RTS_ENABLED	2
#define UART_U1XT_U1RX_U1RTS_ENABLED		1
#define UART_U1XT_U1RX_ENABLED			0
/*  WAKE: Wake-up on Start bit Detect During Sleep Mode Enable bit       */
#define UART_WAKEUP_ENABLED		1
#define UART_WAKEUP_DISABLED		0
/*  LPBACK: UARTx Loopback Mode Select bit      */
#define UART_LOOPBACK_ENABLED		1
#define UART_LOOPBACK_DISABLED		0
/*  ABAUD: Auto-Baud Enable bit     */
#define UART_AUTOBAUD_ENABLED		1
#define UART_AUTOBAUD_DISABLED		0
/*  URXINV: Receive Polarity Inversion bit  */
#define UART_U1RX_IDLE_STATE_ZERO	1
#define UART_U1RX_IDLE_STATE_ONE	0
/*  BRGH: High Baud Rate Enable bit     */
#define UART_4CLOCKS_PER_BIT            1
#define UART_16CLOCKS_PER_BIT           0
/*  PDSEL<1:0>: Parity and Data Selection bits      */
#define UART_9DATA_BITS_NO_PARITY	3
#define UART_8DATA_BITS_ODD_PARITY	2
#define UART_8DATA_BITS_EVEN_PARITY	1
#define UART_8DATA_BITS_NO_PARITY	0
/*  STSEL: Stop Bit Selection bit       */
#define UART_TWO_STOPS_BITS		1
#define UART_ONE_STOPS_BITS		0

/*	R E G I S T E R - U 1 S T A     */
/*  UTXISEL<1:0>: Transmission Interrupt Mode Selection bits    */
#define UART_TX_INTERRUPT_2MODE         2
#define UART_TX_INTERRUPT_1MODE         1
#define UART_TX_INTERRUPT_0MODE         0
/*  UTXINV: IrDA® Encoder Transmit Polarity Inversion bit(      */
#define UART_U1TX_IDLE_STATE_ZERO	1
#define UART_U1TX_IDLE_STATE_ONE	0
/*  UTXBRK: Transmit Break bit      */
#define UART_SYNC_BREAK_ENABLED		1
#define UART_SYNC_BREAK_DISABLED	0
/*  UTXEN: Transmit Enable bit      */
#define UART_TRANSMIT_ENABLED		1
#define UART_TRANSMIT_DISABLED		0
/*  URXISEL<1:0>: Receive Interrupt Mode Selection bits     */
#define UART_RX_INTERRUPT_2MODE		3
#define UART_RX_INTERRUPT_1MODE		2
#define UART_RX_INTERRUPT_0MODE		1
/*  ADDEN: Address Character Detect bit (bit 8 of received data = 1)    */
#define UART_DETECT_MODE_ENABLED	1
#define UART_DETECT_MODE_DISABLED	0

void init_uart_polling(long BaudRate);
void envia_caracter(unsigned char data);
void usart_puts(char* data);

#endif	/* UART_H */

