#include "accelerometer.h"



void ACCEL_initialize(void){

    
    return;
}




unsigned int ACCEL_get(char axis){
    
    return (ADC1_getdata(axis)/27.3)*22; 
}
