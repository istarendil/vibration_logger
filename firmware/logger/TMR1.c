#include "TMR1.h"


void TMR1_initialize (void){
    
    //Inicialización del timer 1
    unsigned int config = ( T1_ON & T1_IDLE_STOP & T1_GATE_OFF & 
                            T1_PS_1_8 & T1_SYNC_EXT_OFF & T1_SOURCE_INT);
    
    unsigned int inter  = (T1_INT_OFF & T1_INT_PRIOR_1);
   
    CloseTimer1();
    ConfigIntTimer1 (inter);
    OpenTimer1 (config,_ADC_SAMPLETIME);

    return;
}

