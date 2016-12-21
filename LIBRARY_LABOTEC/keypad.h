/* 
 * File:   keypad.h
 * Author: robert
 *
 * Created on 12 de diciembre de 2014, 11:43
 */

#ifndef KEYPAD_H
#define	KEYPAD_H

#define PB8 8
#define PB7 7 
#define PB6 6
#define PB5 5
#define PB4 4
#define PB3 3
#define PB2 2
#define PB1 1
#define PB0 0

/* FILAS-SALIDAS */
#define ROW1   PB2
#define ROW2   PB3
#define ROW3   PB4
#define ROW4   PB5
/* COLUMNAS-ENTRADAS */
#define COL1   PB0
#define COL2   PB1
#define COL3   PB7
#define COL4   PB8

#define FILAS     LATB
#define COLUMNAS  PORTB

void keypad_init (void);
char keypad_getc(void);
#endif	/* KEYPAD_H */

