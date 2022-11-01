

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */


#ifndef ACCELEROMETER_H
#define	ACCELEROMETER_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include "adc1.h"


#define     x              2
#define     y              1
#define     z              0

#define _ACCEL_enable      _ENABLE_PIN=1
#define _ACCEL_disable     _ENABLE_PIN=0

void ACCEL_initialize(void);
unsigned int ACCEL_get(char axis); 


#endif	/* XC_HEADER_TEMPLATE_H */

