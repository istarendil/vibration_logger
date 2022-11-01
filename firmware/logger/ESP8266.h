/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef ESP8266_H
#define	ESP8266_H

#include <xc.h>
#include "Configuration.h"


#define _ESP8266resetpin    TRISDbits.TRISD9
#define _ESP8266reset       LATDbits.LATD9

void initilize_ESP8266(void);
char wlan_ESP8266(char id[40],char pw[40]);


#endif	/* XC_HEADER_TEMPLATE_H */

