
/* 
 * File:  timer_adc1 
 * Author: Iztatik
 * Comments: Timer 3 implementado para el control de tiempo de muestreo con el ADC
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef TIMER_ADC1_H
#define TIMER_ADC1_H

#include <xc.h> 
#include "Configuration.h"
#include <timer.h>


#define _timer_period      2499          //2ms;500Hz


void TIMER_ADC_initialize(void);



#endif	/* XC_HEADER_TEMPLATE_H */

