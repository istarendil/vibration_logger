#include "timer_adc1.h"


void TIMER_ADC_initialize(void){
    
    unsigned int config =(T3_ON & T3_IDLE_STOP & T3_GATE_OFF & T3_PS_1_1 & T3_SOURCE_INT);
    unsigned int inter = ( T3_INT_OFF & T1_INT_PRIOR_0);
    unsigned int period=(_timer_period);
    
    
    
    CloseTimer3();
    ConfigIntTimer3(inter);
    OpenTimer3(config,period);    
    
    
    return ;
}


