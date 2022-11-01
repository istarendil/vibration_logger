/* 
 * File: Configuration
 * Author: Iztatik
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef CONFIGURATION_H
#define	CONFIGURATION__H

#include <xc.h>

#define _XTAL_FREQ  20000000
#define _PLL        8
#define _POSTCALER  2
#define _SYS_CLK    (_XTAL_FREQ * _PLL)
#define FCY         ((_SYS_CLK/4)/_POSTCALER)  //20MIPS
 
#include <stdio.h>
#include <stdlib.h>
#include <libpic30.h>
#include "adc1.h"
#include "TMR1.h"
#include "uart1.h"
#include "uart2.h"
#include "ESP8266.h"
#include "DS1302.h"
#include "accelerometer.h"
#include "openlog.h"
#include <libpic30.h>




void SYSTEM_initialize (void);


#endif	/* XC_HEADER_TEMPLATE_H */

