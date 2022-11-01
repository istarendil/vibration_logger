
#include "uart1.h"

void UART1_initialize (void){
        
    unsigned int config = (UART_RX_INT_DIS
                         & UART_TX_INT_DIS);
    
    unsigned int config1 = (UART_EN 
                          & UART_IDLE_STOP 
                          & UART_RX_TX 
                          & UART_DIS_WAKE 
                          & UART_DIS_LOOPBACK 
                          & UART_DIS_ABAUD
                          & UART_NO_PAR_8BIT 
                          & UART_1STOPBIT);
    
    unsigned int config2 = (UART_INT_TX 
                          & UART_TX_PIN_NORMAL 
                          & UART_TX_ENABLE 
                          & UART_INT_RX_CHAR 
                          & UART_ADR_DETECT_DIS
                          & UART_RX_OVERRUN_CLEAR);
    
    unsigned int ubrg = _BAUD_RATE1;
    
    CloseUART1();
    ConfigIntUART1(config);        
    OpenUART1 (config1, config2, ubrg);
    
    return;
}


void UART1_send_string(char str1[30]){
    
    putsUART1((unsigned int *)str1);
    return;
}

