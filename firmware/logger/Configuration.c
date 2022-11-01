
// FOSC
#pragma config FOSFPR = HS2_PLL8        // Oscillator (HS2 w/PLL 8x)
#pragma config FCKSMEN = CSW_FSCM_OFF   // Clock Switching and Monitor (Sw Disabled, Mon Disabled)

// FWDT
#pragma config FWPSB = WDTPSB_16        // WDT Prescaler B (1:16)
#pragma config FWPSA = WDTPSA_512       // WDT Prescaler A (1:512)
#pragma config WDT = WDT_OFF            // Watchdog Timer (Disabled)

// FBORPOR
#pragma config FPWRT = PWRT_16          // POR Timer Value (16ms)
#pragma config BODENV = BORV20          // Brown Out Voltage (Reserved)
#pragma config BOREN = PBOR_OFF         // PBOR Enable (Disabled)
#pragma config MCLRE = MCLR_EN          // Master Clear Enable (Enabled)

// FGS
#pragma config GWRP = GWRP_OFF          // General Code Segment Write Protect (Disabled)
#pragma config GCP = CODE_PROT_OFF      // General Segment Code Protection (Disabled)

// FICD
#pragma config ICS = ICS_PGD            // Comm Channel Select (Use PGC/EMUC and PGD/EMUD)

#include "Configuration.h"


void SYSTEM_initialize (void){
   
                                    /* Configuración de puertos */
    //Puerto A
    TRISAbits.TRISA11 = 1;
    
    //Puerto B
    TRISBbits.TRISB5 = 1;
    
    //Puerto C
    TRISCbits.TRISC13 = 0; 
    TRISCbits.TRISC14 = 0;
    
    //Puerto D
    TRISDbits.TRISD8 = 0;
    
    //Puerto F
    TRISFbits.TRISF0 = 1;    
    TRISFbits.TRISF1 = 1;
    TRISFbits.TRISF6 = 1;
    
    
    initilize_ESP8266();
    __delay_ms(5000);            //Retardo de seguridad para iniciaización de los elementos
    ADC1_initialize();  
    TMR1_initialize();
    DS1302_initialize();
    ACCEL_initialize();
    UART1_initialize(); 
    UART2_initialize();
    OPENLOG_initilize();
    __delay_ms(2000);
    EnableIntU2RX;
    
    SetChanADC12 (ADC_CH0_POS_SAMPLEA_AN0 & ADC_CH0_NEG_SAMPLEA_NVREF ); //Seleccionamos pin de muestreo del ADC
    
    return;
}




