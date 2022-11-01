

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef DS1302_H
#define	DS1302_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include "uart1.h"

/*Pinout definitions*/
#define _CLKoutput   TRISBbits.TRISB10 =0
#define _IOoutput    TRISBbits.TRISB11 =0
#define _IOinput     TRISBbits.TRISB11 =1
#define _CEoutput    TRISBbits.TRISB12 =0

#define _ds1302SCLK     LATBbits.LATB10
#define _ds1302IO       LATBbits.LATB11
#define _ds1302IOin     PORTBbits.RB11
#define _ds1302CE       LATBbits.LATB12

/*Types definitions for write/read functions*/
#define _seconds    0x80
#define _minutes    0x82
#define _hours      0x84
#define _date       0x86
#define _month      0x88
#define _day        0x8A
#define _year       0x8C

/*Functions definitions*/
void DS1302_initialize(void);
void DS1302_write(int type, int data);
char DS1302_read(char type);
//char DS1302_bin2bcd(char tp, char bod);
char DS1302_bcd2bin(char tp, char bin);
char DS1302_rgtclean (int t, char d);

#endif	/* XC_HEADER_TEMPLATE_H */

