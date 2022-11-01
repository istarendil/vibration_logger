#include "ESP8266.h"


void initilize_ESP8266(void){ 
   _ESP8266resetpin = 0;
   _ESP8266reset = 0;

    return;
}


char wlan_ESP8266(char id[40],char pw[40]){
    
    _ESP8266reset = 1;
    __delay_ms(400);         //Tiempo para enviar los datos del router al módulo (no cambiar))
    UART2_send_string("-");
    UART2_send_string(id);
    UART2_send_string("-");
    UART2_send_string(" ");
    UART2_send_string("-");
    UART2_send_string(pw);
    UART2_send_string("-");
    
    return 0;
    
}