#include <xc.h>
#define FCY             40000000UL
#include <libpic30.h>
#include "keypad.h"

void keypad_init (void){

   TRISB = (1<<COL4)|(1<<COL3)|(1<<COL2)|(1<<COL1);       // Setup as Input
   TRISB &= ~(1<<ROW4)&~(1<<ROW3)&~(1<<ROW2)&~(1<<ROW1);  // Setup as Output

   CNPU1bits.CN4PUE=1;     //  Enabled Pull-Up
   CNPU1bits.CN5PUE=1;     //  Enabled Pull-Up
   CNPU2bits.CN22PUE=1;    //  Enabled Pull-Up
   CNPU2bits.CN23PUE=1;    //  Enabled Pull-Up

   LATB = (1<<PB7)|(1<<PB6)|(1<<PB5)|(1<<PB4);
   LATB &= ~(1<<PB3)&~(1<<PB2)&~(1<<PB1)&~(1<<PB0);

}

char keypad_getc(void){

char letras[4][4]={  {'1','2','3','A'},
                     {'4','5','6','B'},
                     {'7','8','9','C'},
                     {'*','0','#','D'}};
int  i=0;
char valor=0;

for(i=0;i<4;i++){

   if(i==0){

      FILAS = (1<<COL4)|(1<<COL3)|(1<<COL2)|(1<<COL1)|(1<<ROW4)|(1<<ROW3)|(1<<ROW2)|(0<<ROW1);
      __delay_us(100);
      while (!(COLUMNAS & (1<<COL1))){valor=letras[0][0];}   //1
      while (!(COLUMNAS & (1<<COL2))){valor=letras[0][1];}   //2
      while (!(COLUMNAS & (1<<COL3))){valor=letras[0][2];}   //3
      while (!(COLUMNAS & (1<<COL4))){valor=letras[0][3];}   //A
   }

   if(i==1){
      FILAS = (1<<COL4)|(1<<COL3)|(1<<COL2)|(1<<COL1)|(1<<ROW4)|(1<<ROW3)|(0<<ROW2)|(1<<ROW1);
      __delay_us(100);
      while (!(COLUMNAS & (1<<COL1))){valor=letras[1][0];}   //4
      while (!(COLUMNAS & (1<<COL2))){valor=letras[1][1];}   //5
      while (!(COLUMNAS & (1<<COL3))){valor=letras[1][2];}   //6
      while (!(COLUMNAS & (1<<COL4))){valor=letras[1][3];}   //B
   }

   if(i==2){
      FILAS = (1<<COL4)|(1<<COL3)|(1<<COL2)|(1<<COL1)|(1<<ROW4)|(0<<ROW3)|(1<<ROW2)|(1<<ROW1);
      __delay_us(100);
      while (!(COLUMNAS & (1<<COL1))){valor=letras[2][0];}   //7
      while (!(COLUMNAS & (1<<COL2))){valor=letras[2][1];}   //8
      while (!(COLUMNAS & (1<<COL3))){valor=letras[2][2];}   //9
      while (!(COLUMNAS & (1<<COL4))){valor=letras[2][3];}  //C
   }

   if(i==3){
      FILAS = (1<<COL4)|(1<<COL3)|(1<<COL2)|(1<<COL1)|(0<<ROW4)|(1<<ROW3)|(1<<ROW2)|(1<<ROW1);
      __delay_us(100);
      while (!(COLUMNAS & (1<<COL1))){valor=letras[3][0];}   //*
      while (!(COLUMNAS & (1<<COL2))){valor=letras[3][1];}   //0
      while (!(COLUMNAS & (1<<COL3))){valor=letras[3][2];}   //+
      while (!(COLUMNAS & (1<<COL4))){valor=letras[3][3];}   //D
      }
   }

   return valor;
}

