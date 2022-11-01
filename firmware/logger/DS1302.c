#include "DS1302.h"

void DS1302_initialize(void){
    
    _CLKoutput;
    _IOoutput ;
    _CEoutput;
    
    _ds1302SCLK=0;
    _ds1302IO=0;
    _ds1302CE=0;
    
    /*DS1302_write(_seconds, 0x00);
    DS1302_write(_minutes, 0x35);
    DS1302_write(_hours,   0x02);
    
    DS1302_write(_day,     0x02);
    DS1302_write(_date,    0x21);
    DS1302_write(_month,   0x01);
    DS1302_write(_year,    0x19);*/
    return;
}

void DS1302_write(int type, int data){
    char i;
    int buff= (data<<8)|type;
    
     _IOoutput;
     _ds1302CE=1;
     __delay_us(1);
 
     for(i=0;i<16;i++){         
       _ds1302IO = (buff>>i)&0x01; 
       __delay_us(4);
       _ds1302SCLK=1;
       __delay_us(4);
       _ds1302SCLK=0;}
     
     _ds1302SCLK=0;
     _ds1302IO=0;
     _ds1302CE=0;
    
    return;
}


char DS1302_read(char type){
     char value=0x00; 
     char i,buff[8];
     type++;
     
     _IOoutput;    
     _ds1302CE=1;
     __delay_us(1);

     for(i=0;i<16;i++){  
       if (i==8) _IOinput;  
       if (i<=7) _ds1302IO = (type>>i)&0x01;
       __delay_us(4);
       if (i>7)      buff[i-8]=_ds1302IOin;
       _ds1302SCLK=1;
       __delay_us(4);
       _ds1302SCLK=0; }
     
     _ds1302SCLK=0;
     _ds1302IO=0;
     _ds1302CE=0;
     
    for(i=7;i>=0;i--) value=(value<<1)+ buff[i];  
    value = DS1302_bcd2bin(type--,value);
    return value;
}


char DS1302_bcd2bin(char tp, char bcd){
    char i,n = bcd/16;
    
    bcd = DS1302_rgtclean (tp,bcd);
    for(i=0;i<n;i++){bcd=bcd-6;}
    return bcd;
}


char DS1302_rgtclean (int t, char d){
    
    switch(t){
        
        case (_seconds):
           d= d & 0b01111111; 
            break;
        case (_minutes):
            d= d & 0b01111111;
            break;   
        case (_hours):
            d= d & 0b00011111;
            break;
        case (_date):
            d= d & 0b00111111;
            break;
        case (_month):
            d= d & 0b00011111;
            break;
        case (_day):
            d= d & 0b00000111;
            break;
        case (_year):
            d= d & 0b11111111;
            break;
        default: break;        
    }
    return d;
}