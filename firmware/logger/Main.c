/*
 * File:   Main.c
 * Author: Carlos Alberto Sánchez Delgado
 *
 * Created on 12 de julio de 2016, 11:01 AM
 */

#include "Configuration.h"


#define button PORTFbits.RF0
#define LED_batt   LATCbits.LATC13 
#define LED_active LATCbits.LATC14 
#define LED_on     LATDbits.LATD8 
char rec[20], function_flag=0,file_flag=0;

int main(void) { 
    unsigned int accel_dataX,accel_dataY,accel_dataZ,batt_stat ;  
    unsigned int counter=0;
    SYSTEM_initialize();

    LED_on = 1;
    LED_batt = 1;
    
    while (1){ 
        if(button&&!function_flag){function_flag =1;file_flag=1;__delay_ms(300);while(button);__delay_ms(200);}      
        if(file_flag==1){file_flag=0;OPENLOG_newfile();}

        while (TMR1_FLAG && function_flag){    
            
            LED_active =1;
            accel_dataX = ACCEL_get(x);
            accel_dataY = ACCEL_get(y);
            accel_dataZ = ACCEL_get(z);
            batt_stat = BATT_get();
            OPENLOG_completewrite(counter++,accel_dataX,accel_dataY,accel_dataZ);  
            if (batt_stat<=2100) LED_batt=1;                     // aprox 6.10v de las pilas 
            else LED_batt=0;
            TMR1_FLAG=0;
        }
        if(button&&function_flag){function_flag =0;file_flag=2;__delay_ms(300);while(button);__delay_ms(200);}
        if(file_flag==2) {OPENLOG_printtime();file_flag=0;LED_active =0;counter=0;}
    }
    return 0;
}

