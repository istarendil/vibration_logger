
/* 
 * File: Accelerometer
 * Author: Iztatik
 * Comments:  Drive for an analog accelerometer KXR94
 * Revision history: v1.0
 */

#ifndef TMR1_H
#define	TMR1_H 

#include <xc.h>  
#include "Configuration.h"
#include <timer.h>

#define _TIMECONST  2.5                        //Constante a 1 us   FCY/(1000000*Prescaler)
#define _ADC_SAMPLETIME   _TIMECONST*5000      //Delay entre cada interrupción para la lectura del ADC   _TIMECONST* tiempo en us(5000)
#define TMR1_FLAG          IFS0bits.T1IF


void TMR1_initialize (void);



#endif	/* XC_HEADER_TEMPLATE_H */

