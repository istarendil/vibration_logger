#include "openlog.h"

int file_number;

void OPENLOG_initilize(){
    
    char ssid[40],pass[40],num[40];
    UART1_send_string("read WLAN.txt 27\r");
    OPENLOG_get_string(ssid);
    OPENLOG_get_string(pass);
    OPENLOG_parser(ssid);
    OPENLOG_parser(pass);
    __delay_ms(50);
    UART1_send_string("read COUNT.txt \r");
    OPENLOG_get_string(num);
    OPENLOG_parser(num);
    __delay_ms(50);
    wlan_ESP8266(ssid,pass);
    file_number = atoi(num);
    return;
}


char OPENLOG_get_string(char* punt){
    char buffer,f=0x00;  
    
    while(f!='"'){
        while(!DataRdyUART1());
        f = getcUART1();
        if (f == '"'){*punt='"'; punt++;}
        
    }
    while (1){      
        while(!DataRdyUART1());
        buffer=getcUART1();  
        if (buffer == '>') return 0;
        if (buffer == '"') {*punt='"';return 1;}
        *punt=buffer;
        punt++; 
    } 
    return 0;                                //Lectura correcta
}


void OPENLOG_parser(char* punt){
    char buff,c=1;
    
    while (*(punt+c)!='"'){
        buff=*(punt+c);
        *(punt+c-1)=buff;
        c++;
    }
    for(c=c;c<40;c++) *(punt+c-1)=0x00;
    
    return;
}


void OPENLOG_completewrite(unsigned int a, unsigned int b, unsigned int c, unsigned int d){
    
    char string[7];
    unsigned int buff[4],count; 
     
    
    buff[0]=a;
    buff[1]=b;
    buff[2]=c;
    buff[3]=d;
    
    for ( count=0; count<4;count++) {
        sprintf(string, "%d", buff[count]);
        UART1_send_string(string);
        while(BusyUART1());
        if (count<3) UART1_send_string(";");
        else UART1_send_string("\r");
        
        
    }  
    return;
}

void OPENLOG_comandmode(void){
    char i;
    
    getcUART1();
    UART1_send_string("\r");    
    for(i=0;i<3;i++){__delay_ms(50);putcUART1(0x1A);}
    __delay_ms(50);
    return;
}


void OPENLOG_newfile(void){
    
    char buff[5];
    
    file_number++;
    sprintf(buff, "%d", file_number);
    OPENLOG_comandmode();
    UART1_send_string("rm COUNT.TXT\r");
    __delay_ms(50);
    UART1_send_string("rm COUNT.TXT\r");
    __delay_ms(50);
    UART1_send_string("append COUNT.TXT\r");
    __delay_ms(50);
    putcUART1('"');
    UART1_send_string(buff);
    putcUART1('"');
    OPENLOG_comandmode();
    UART1_send_string("append FILE");
    UART1_send_string(buff);
    UART1_send_string(".TXT\r");
    UART1_send_string("Analizador de vibraciones ");
    UART1_send_string("FI-UAEMex\n");
    OPENLOG_printtime();
    UART1_send_string("CONTEO;EJEX;EJEY;EJEZ\r\n");
    
    return;
}



void OPENLOG_printtime(void){
    char time[4];
    
    switch(DS1302_read(_day)){
        case(1):UART1_send_string("Domingo ");break;
        case(2):UART1_send_string("Lunes: ");break;
        case(3):UART1_send_string("Martes: ");break;
        case(4):UART1_send_string("Miércoles: ");break;
        case(5):UART1_send_string("Jueves: ");break;
        case(6):UART1_send_string("Viernes: ");break;
        case(7):UART1_send_string("Sábado: ");break;
        default: break; }
    
    sprintf(time, "%d", DS1302_read(_date));
    UART1_send_string(time);
    UART1_send_string("/");
    sprintf(time, "%d", DS1302_read(_month));
    UART1_send_string(time);
    UART1_send_string("/");
    sprintf(time, "%d", DS1302_read(_year));
    UART1_send_string(time);
    UART1_send_string("  ");
    
    sprintf(time, "%d", DS1302_read(_hours));
    UART1_send_string(time);
    UART1_send_string(":");
    sprintf(time, "%d", DS1302_read(_minutes));
    UART1_send_string(time);
    UART1_send_string(":");
    sprintf(time, "%d", DS1302_read(_seconds));
    UART1_send_string(time);
    UART1_send_string("\n");
    
    return;
}