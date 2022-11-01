
/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

#ifndef OPENLOG_H
#define	OPENLOG_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include "Configuration.h"

#define OPENLOG_write UART1_send_string 

void OPENLOG_initilize(void);
char OPENLOG_get_string(char* punt);
void OPENLOG_parser(char* punt);
void OPENLOG_completewrite(unsigned int a, unsigned int b, unsigned int c,unsigned int d);
void OPENLOG_comandmode(void);
void OPENLOG_newfile(void);
void OPENLOG_printtime(void);


#endif	/* XC_HEADER_TEMPLATE_H */

