#include "uart2.h"

extern char rec[20], function_flag,file_flag;

void UART2_initialize (void){
        
    unsigned int config = (UART_RX_INT_DIS
                         & UART_RX_INT_PR2
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
    
    unsigned int ubrg = _BAUD_RATE2;
    CloseUART2();
    ConfigIntUART2(config);        
    OpenUART2 (config1, config2, ubrg);
    return;
}

void UART2_send_string(char str2[20]){
    
    putsUART2((unsigned int *)str2);
    
    return;
}
void UART2_get_string(char* punt){

    do{
     
        while(!DataRdyUART2());
        *punt= getcUART2();
        punt++;   
        
    }while((*punt));

    return;
}

//ISR para recepción de datos

  void __attribute__((interrupt,no_auto_psv)) _U2RXInterrupt(void){
      
      IFS1bits.U2RXIF = 0;        //Ponemos a 0 el flag de la interrupcion de recepcion 
      char buff;
    
      buff = getcUART2();
      if (buff=='s') {function_flag =1;file_flag=1;}
      else if(buff=='e') {function_flag =0;file_flag=2;}
      if(U2STAbits.OERR) U2STAbits.OERR=0;//si hay error de overflow es borrado    
      return;
 }
