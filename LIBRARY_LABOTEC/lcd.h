/*
 * File:   lcd.h
 * Author: robert
 *
 * Created on 11 de diciembre de 2014, 11:21 PM
 */

#ifndef LCD_H
#define	LCD_H


//Uncomment this if LCD 4 bit interface is used
//******************************************
#define LCD_4bit
//***********************************************
#define LCD_RS	1 	//define MCU pin connected to LCD RS
#define LCD_RW	2 	//define MCU pin connected to LCD R/W
#define LCD_E	3	//define MCU pin connected to LCD E
#define LCD_D0	0	//define MCU pin connected to LCD D0
#define LCD_D1	1	//define MCU pin connected to LCD D1
#define LCD_D2	2	//define MCU pin connected to LCD D1
#define LCD_D3	3	//define MCU pin connected to LCD D2
#define LCD_D4	4	//define MCU pin connected to LCD D3
#define LCD_D5	5	//define MCU pin connected to LCD D4
#define LCD_D6	6	//define MCU pin connected to LCD D5
#define LCD_D7	7	//define MCU pin connected to LCD D6
#define LDP LATC	//define MCU port connected to LCD data pins
#define LCP LATC	//define MCU port connected to LCD control pins
#define LDDR TRISC	//define MCU direction register for port connected to LCD data pins
#define LCDR TRISC	//define MCU direction register for port connected to LCD control pins

#define LCD_CGRAM           6	//DB6: set CG RAM address
#define LCD_DDRAM           7	//DB7: set DD RAM address

/*
 * Function set
 * RS R/W DB7 DB6 DB5 DB4 DB3 DB2 DB1 DB0
 *	0 	0 	0 	0 	1 	DL 	N 	F 	? 	?
 *	(DL) data length				DL=1: 8 bits, 	DL=0: 4 bits
 *	(N)  number of display lines  	N=1:  2 lines, 	 N=0: 1 line
 *	(F)	 character font  			F=1:  5x10 dots, F=0: 5x8 dots
 */
#define  SETLCD_4BITS_2LINE    	0b00101000
/*
 * Display	on/off
 * RS R/W DB7 DB6 DB5 DB4 DB3 DB2 DB1 DB0
 *  0 	0 	0 	0 	0 	0 	1 	D 	C 	B
 *	Sets entire Display on/off				(D).
 *	Cursor on/off 							(C).
 *	Blinking of cursor position character 	(B).
 */
#define  DISPLAY_ALL_ON				0b00001111
#define  DISPLAY_ON_D_OFF_CB		0b00001100
#define  DISPLAY_ON_D_ON_C_OFF_B	0b00001110
#define  DISPLAY_ON_D_OFF_C_ON_B	0b00001101
/*
 * Entry mode set
 * Sets cursor move direction and specifies display shift.
 * These operations are performed during data write and read.
 * RS R/W DB7 DB6 DB5 DB4 DB3 DB2 DB1 DB0
 *  0 	0 	0 	0 	0 	0 	0 	1  I/D 	S
 *  I/D=1	: Increment
 *  I/D=0	: Decrement
 *  S=1	: Accompanies display shift
 */
#define	 EMS_INC_S			0b00000110
/*
 * Cursor or display shift
 * Moves cursor and shifts display without changing DDRAM contents.
 * RS R/W DB7 DB6 DB5 DB4 DB3 DB2 DB1 DB0
   	0 	0 	0 	0 	0 	1  S/C R/L 	? 	?
	S/C=1: Display shift			S/C=0: Cursor move
	R/L=1: Shift to the right		R/L=0: Shift to the left
 */
#define	DISP_MOVE_RIGHT		0b00011100
#define	DISP_MOVE_LEFT		0b00011000
#define	CURSOR_MOVE_RIGHT	0b00010100
#define	CURSOR_MOVE_LEFT	0b00010000
/*
 * Set	DDRAM
 * RS R/W DB7 DB6 DB5 DB4 DB3 DB2 DB1 DB0
 *  0 	0 	1  ADD ADD ADD ADD ADD ADD ADD
 */
#define LCD_LINE0_DDRAMADDR		0x00
#define LCD_LINE1_DDRAMADDR		0x40
#define LCD_LINE2_DDRAMADDR		0x14
#define LCD_LINE3_DDRAMADDR		0x54
/*******************************************************************/
#define	 RETURN_HOME		0b00000010
#define  CLEAR_DISPLAY   	0b00000001
/********************************************************************/

void LCDsendChar(unsigned char);				//forms data ready to send to 74HC164
void LCDsendCommand(unsigned char);				//forms data ready to send to 74HC164
void LCDinit(void);								//Initializes LCD
void LCDstring(unsigned char*, unsigned char);	//Outputs string to LCD
void LCDGotoXY(unsigned char, unsigned char);	//Cursor to X Y position
void write_CGRAM(const unsigned char*,unsigned char);
void LCDdefinechar(unsigned char*,unsigned char);
void LCDsend_var(unsigned int);



#ifdef	__cplusplus
extern "C" {
#endif


#ifdef	__cplusplus
}
#endif

#endif	/* LCD_H */

