/* 
 * File:   adc.h
 * Author: robert
 *
 * Created on 30 de diciembre de 2014, 02:22 AM
 */

#ifndef ADC_H
#define	ADC_H

/****	AD1CON1 REGISTER	****/
#define ADC_OPERATING_ON                1
#define ADC_OPERATING_OFF		0

#define ADC_DISCONTINUE_IDLE_MODE	1
#define ADC_CONTINUE_IDLE_MODE		0

#define ADC_12BIT_OPERATION		1
#define ADC_10BIT_OPERATION		0

#define ADC_SIGNED_FRACTIONAL		3
#define ADC_FRACTIONAL			2
#define ADC_SIGNED_INTEGER		1
#define ADC_INTEGER			0

#define ADC_INTERNAL_COUNTER		7
#define ADC_CLEARING_SAMPLE		0

#define ADC_SAMPLES_SIMULTANEUS		1
#define ADC_SAMPLES_INDIVUDAL		0

#define ADC_SAMPLES_AUTOSET		1
#define ADC_SAMPLES_NO_AUTOSET		0

#define ADC_SAMPLE_HOLD_SAMPLING	1
#define ADC_SAMPLE_HOLD_HOLDING		0

/****	ADCON2 REGISTER	****/
#define ADC_EXTREFPLUS_EXTREFMINUS	3
#define ADC_AVDD_EXTREFMINUS		2
#define ADC_EXTREFPLUS_AVSS		1
#define ADC_AVDD_AVSS			0

#define ADC_SCAN_INPUTS			1
#define ADC_NO_SCAN_INPUTS		0

#define ADC_CONVERT_CH0			0
#define ADC_CONVERT_CH0_CH1		1
#define ADC_CONVERT_CH0_CH1_CH2_CH3	2


/****	AD1CON3 REGISTER	****/

#define ADC_INTERNAL_CLOCK	1
#define ADC_SYSTEM_CLOCK	0

void InitADC(void);
int ReadADC(void);

#endif	/* ADC_H */

