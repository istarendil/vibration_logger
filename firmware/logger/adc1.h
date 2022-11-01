/* 
 * File: adc1
 * Author:  Iztatik
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef ADC1_H
#define	ADC1_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <adc12.h>

#define Tad         700                //tad=700ns

#define _sampling    ADCON1bits.SAMP   // Read 1 = sampling in process. 0 = no sampling
                                       // Write 1= start sampling. 0 = Stop sampling

void ADC1_initialize(void);
unsigned int ADC1_getdata(char chan);       // Secuencia de adquisición completa de 1 dato a 2ms
unsigned int BATT_get(void); 

#endif	/* XC_HEADER_TEMPLATE_H */

