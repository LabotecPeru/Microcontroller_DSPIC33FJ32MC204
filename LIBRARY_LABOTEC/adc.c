#include <xc.h>
#include "../LIBRARY_LABOTEC/system.h"
#include <libpic30.h>
#include "adc.h"

void InitADC(void){

    AD1PCFGL &=~(1<<0);     ////	PIN0 in Analoge mode
    //ConfigPinsAsAnalog();
    AD1CON1 = 0;		// Clear it
    AD1CON1bits.AD12B = ADC_12BIT_OPERATION;	// 12-bit, 1-channel ADC operation
    AD1CON1bits.FORM  = ADC_INTEGER;            // Integer (DOUT = 0000 dddd dddd dddd)
    AD1CON1bits.SSRC  = ADC_CLEARING_SAMPLE;	// SSRC bit = 000
    AD1CON2bits.CSCNA = ADC_NO_SCAN_INPUTS;	// NO Scan required
    AD1CON2bits.VCFG  = ADC_AVDD_AVSS;          // AVss and AVdd are used as Vref+/-
    //AD1CON3 = 0x1F02; 		// max sample time = 31Tad, Tad = 2 x Tcy = 125ns >75ns
    AD1CON3bits.ADRC = 0; // ADC Clock is derived from Systems Clock
    AD1CON3bits.SAMC = 0; // Auto Sample Time = 0 * TAD
    AD1CON3bits.ADCS = 5; // ADC Conversion Clock TAD = TCY * (ADCS + 1) = (1/40M) * 6 =
                          // 150 ns (6.67 MHz)
                          // ADC Conversion Time for 12-bit Tconv = 14 * TAD = 2100 ns (476.1 KHz)

    AD1CON1bits.ASAM = ADC_SAMPLES_NO_AUTOSET;

    IFS0bits.AD1IF = 0;		// Clear the A/D interrupt flag bit
    IEC0bits.AD1IE = 0;		// Do Not Enable A/D interrupt

    AD1CHS0bits.CH0SA = 0;	// Connect ANX to CH0 input
    AD1CON1bits.ADON = ADC_OPERATING_ON;	// turn on the ADC
}

int ReadADC(){

    //if SSRC=0 & ASAM=0
    //  Manual Sample and Manual Conversion Sequence
    
    AD1CON1bits.SAMP = 1;       //  start sampling.
    asm("nop");asm("nop");      //  2 TCY
    AD1CON1bits.SAMP = 0;       //  end sampling and start conversion
    while (!AD1CON1bits.DONE);  //  wait to complete the conversion
    return ADC1BUF0;            //  read the conversion result
}
