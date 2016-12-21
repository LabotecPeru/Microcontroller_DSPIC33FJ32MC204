#include <xc.h>
#define FCY             40000000UL
#include <libpic30.h>
#include "lcd.h"

void LCDsendChar(unsigned char ch){		//Sends Char to LCD
	//4 bit part
	LDP=(ch&0b11110000);
	LCP|=1<<LCD_RS;
	LCP|=1<<LCD_E;
	__delay_ms(1);
	LCP&=~(1<<LCD_E);
	LCP&=~(1<<LCD_RS);
	__delay_ms(1);
	LDP=((ch&0b00001111)<<4);
	LCP|=1<<LCD_RS;
	LCP|=1<<LCD_E;
	__delay_ms(1);
	LCP&=~(1<<LCD_E);
	LCP&=~(1<<LCD_RS);
	__delay_ms(1);

}
void LCDsendCommand(unsigned char cmd){	//Sends Command to LCD
	//4 bit part
	LDP=(cmd&0b11110000);
	LCP|=1<<LCD_E;
	__delay_ms(1);
	LCP&=~(1<<LCD_E);
	__delay_ms(1);
	LDP=((cmd&0b00001111)<<4);
	LCP|=1<<LCD_E;
	__delay_ms(1);
	LCP&=~(1<<LCD_E);
	__delay_ms(1);

}
void LCDinit(void){//Initializes LCD

	//4 bit part
	__delay_ms(15);
	LDP=0x00;
	LCP=0x00;
	LDDR =0<<LCD_D7|0<<LCD_D6|0<<LCD_D5|0<<LCD_D4;
	LCDR =0<<LCD_E|0<<LCD_RW|0<<LCD_RS;
   //---------one------
	LDP=0<<LCD_D7|0<<LCD_D6|1<<LCD_D5|1<<LCD_D4; //4 bit mode
	LCP|=1<<LCD_E|0<<LCD_RW|0<<LCD_RS;
	__delay_ms(1);
	LCP&=~(1<<LCD_E);
	__delay_ms(1);
	//-----------two-----------
	LDP=0<<LCD_D7|0<<LCD_D6|1<<LCD_D5|1<<LCD_D4; //4 bit mode
	LCP|=1<<LCD_E|0<<LCD_RW|0<<LCD_RS;
	__delay_ms(1);
	LCP&=~(1<<LCD_E);
	__delay_ms(1);
	//-------three-------------
	LDP=0<<LCD_D7|0<<LCD_D6|1<<LCD_D5|0<<LCD_D4; //4 bit mode
	LCP|=1<<LCD_E|0<<LCD_RW|0<<LCD_RS;
	__delay_ms(1);
	LCP&=~(1<<LCD_E);
	__delay_ms(1);
	//--------4 bit--dual line--5x8 dots---------------
	LCDsendCommand(SETLCD_4BITS_2LINE);
   //-----increment address, invisible cursor shift------
	LCDsendCommand(DISPLAY_ON_D_OFF_CB);
}

void LCDstring(unsigned char* data, unsigned char nBytes){	//Outputs string to LCD
	register unsigned char i=0;

	for(i=0; i<nBytes; i++){	// print data
		LCDsendChar(data[i]);
	}
}

void LCDGotoXY(unsigned char x, unsigned char y){		//Cursor to X Y position
	register unsigned char DDRAMAddr;

	switch(y){		// remap lines into proper order
	case 0: DDRAMAddr = LCD_LINE0_DDRAMADDR+x; break;
	case 1: DDRAMAddr = LCD_LINE1_DDRAMADDR+x; break;
	case 2: DDRAMAddr = LCD_LINE2_DDRAMADDR+x; break;
	case 3: DDRAMAddr = LCD_LINE3_DDRAMADDR+x; break;
	default: DDRAMAddr =LCD_LINE0_DDRAMADDR+x;break;
	}
	LCDsendCommand(1<<LCD_DDRAM|DDRAMAddr);	// set data address
}
/*  Funcion para escribir en la CGRAM
 *	DATASHEET HD44780U (LCD-II) (Dot Matrix Liquid Crystal Display Controller/Driver)
 *	page 19.
 * */
void LCDdefinechar(unsigned char *car,unsigned char CGRAM_dir){
	unsigned char i=0,a=0;
	a=(CGRAM_dir<<3)|1<<LCD_CGRAM;		//	posiciona en la CGRAM address
	for(i=0;i<8;i++){
		LCDsendChar(car[i]);			//	escribe caracter
		LCDsendCommand(a++);			//	incrementa la direccion para la data
	}
}

void LCDsend_var(unsigned int num) //Outputs string to LCD
{
   unsigned char millares=0,centenas = 0, decenas = 0, unidades = 0;

   while (num >= 1000) {
         num-=1000;
         millares++;
      }

   while (num >= 100) {
      num-=100;
      centenas++;
   }
   while (num >= 10) {
      num-=10;
      decenas++;
   }
   unidades = num;

   if(millares!= 0 ){
	  LCDsendChar(millares+48);
   	  LCDsendChar(centenas+48);
   	  LCDsendChar(decenas+48);
   	  LCDsendChar(unidades+48);

   }else
	  if(centenas!= 0 ){
	  LCDsendChar(centenas+48);
	  LCDsendChar(decenas+48);
	  LCDsendChar(unidades+48);

   }else{
      if(decenas != 0){
    	  LCDsendChar(decenas+48);
    	  LCDsendChar(unidades+48);
      }else{
    	  LCDsendChar(unidades+48);
      }
   }
}

