

/* 
 * File: uart2
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef UART2_H
#define	UART2_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include "Configuration.h"
#include <uart.h>

#define _BAUD2 57600
#define _BAUD_RATE2 ((FCY/_BAUD2)/16)-1


void UART2_initialize (void);
void UART2_send_string(char str[20]);
void UART2_get_string(char* str);
void _ISR _U2RXInterrupt(void);


#endif	/* XC_HEADER_TEMPLATE_H */

