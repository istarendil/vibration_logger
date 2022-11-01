/* 
 * File: uart1
 * Author: Iztatik 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef UART1_H
#define	UART1_H

#include "Configuration.h"
#include <uart.h>

#define _BAUD1 57600
#define _BAUD_RATE1 ((FCY/_BAUD1)/16)-1


void UART1_initialize (void);

void UART1_send_string(char str1[30]);



#endif	/* XC_HEADER_TEMPLATE_H */

