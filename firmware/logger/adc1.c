

#include "adc1.h"


void ADC1_initialize(void){

   unsigned int config1=(ADC_MODULE_ON           //ADC module ON
                       & ADC_IDLE_STOP           //When procesosr is in IDLE state ADC is stopped
                       & ADC_FORMAT_INTG         //Integer format output in buffer
                       & ADC_CLK_AUTO           //Conversion sequence started automatically
                       & ADC_AUTO_SAMPLING_ON    // Sampling sequence automatically started 
                       & ADC_SAMP_ON);           // Sample sequence on by the moment
   
   unsigned int config2=(ADC_VREF_AVDD_AVSS        // Voltage reference are GND and VCC
                       & ADC_SCAN_ON             //ADC scan on
                       & ADC_ALT_INPUT_OFF        // Inputs come from MUXA
                       & ADC_ALT_BUF_OFF);        //16-word buffer 
   
   unsigned int config3=(ADC_SAMPLE_TIME_3        //ADC Auto Sample Time 3Tad. (1Tad min)
                       & ADC_CONV_CLK_SYSTEM      //ADC Conversion from system clock.
                       & ADC_CONV_CLK_25Tcy );    //14TCY Conversion clk time (Tad) = 700ns. (666.6 min for vdd/vss ref)
  
   unsigned int configport=(ENABLE_AN0_ANA & 
                            ENABLE_AN1_ANA & 
                            ENABLE_AN2_ANA &
                            ENABLE_AN3_ANA &
                            ENABLE_AN4_ANA &
                            ENABLE_AN5_ANA &
                            ENABLE_AN6_ANA &
                            ENABLE_AN7_ANA &
                            ENABLE_AN8_ANA &
                            ENABLE_AN9_ANA );   //Definitions of which pins are analog or digital
                            
   
   unsigned int configscan= (SCAN_ALL );
  
    
   CloseADC12();
   ConfigIntADC12 (ADC_INT_DISABLE);
   OpenADC12(config1,config2,config3,configport,configscan);
   
    return;
}


unsigned int ADC1_getdata(char chan){
    
    
    while (_sampling);        //Wait until sampling ends and conversion starts 
    while(BusyADC12());       //Wait until conversion ends  // 700ns 
    return ReadADC12(chan);       // Aquire data from ADC buffer
    
}


unsigned int BATT_get(void){
    
    return (ADC1_getdata(4)/27.3)*22; 
}