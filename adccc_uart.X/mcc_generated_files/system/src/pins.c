/**
 * Generated Driver File
 * 
 * @file pins.c
 * 
 * @ingroup  pinsdriver
 * 
 * @brief This is generated driver implementation for pins. 
 *        This file provides implementations for pin APIs for all pins selected in the GUI.
 *
 * @version Driver Version 3.1.1
*/

/*
? [2025] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#include "../pins.h"

void (*IO_RA0_InterruptHandler)(void);

void PIN_MANAGER_Initialize(void)
{
   /**
    LATx registers
    */
    LATA = 0x0;
    LATB = 0x0;
    LATC = 0x18;
    LATD = 0x0;
    LATE = 0x0;
    LATF = 0x0;
    /**
    ODx registers
    */
    ODCONA = 0x0;
    ODCONB = 0x0;
    ODCONC = 0x18;
    ODCOND = 0x0;
    ODCONE = 0x0;
    ODCONF = 0x0;

    /**
    TRISx registers
    */
    TRISA = 0xFF;
    TRISB = 0xEF;
    TRISC = 0x67;
    TRISD = 0xFF;
    TRISE = 0xF;
    TRISF = 0xFF;

    /**
    ANSELx registers
    */
    ANSELA = 0xFE;
    ANSELB = 0xCF;
    ANSELC = 0x67;
    ANSELD = 0xFF;
    ANSELE = 0x7;
    ANSELF = 0xFF;

    /**
    WPUx registers
    */
    WPUA = 0x1;
    WPUB = 0x0;
    WPUC = 0x0;
    WPUD = 0x0;
    WPUE = 0x0;
    WPUF = 0x0;


    /**
    SLRCONx registers
    */
    SLRCONA = 0xFF;
    SLRCONB = 0xFF;
    SLRCONC = 0xFF;
    SLRCOND = 0xFF;
    SLRCONE = 0x7;
    SLRCONF = 0xFF;

    /**
    INLVLx registers
    */
    INLVLA = 0xFF;
    INLVLB = 0xFF;
    INLVLC = 0xFF;
    INLVLD = 0xFF;
    INLVLE = 0xF;
    INLVLF = 0xFF;

   /**
    RxyI2C | RxyFEAT registers   
    */
    RB1I2C = 0x0;
    RB2I2C = 0x0;
    RC3I2C = 0x0;
    RC4I2C = 0x0;
    /**
    PPS registers
    */
    U2RXPPS = 0xD; //RB5->UART2:RX2;
    RB4PPS = 0x18;  //RB4->UART2:TX2;
    I2C1SCLPPS = 0x13;  //RC3->I2C1:SCL1;
    RC3PPS = 0x20;  //RC3->I2C1:SCL1;
    I2C1SDAPPS = 0x14;  //RC4->I2C1:SDA1;
    RC4PPS = 0x21;  //RC4->I2C1:SDA1;

   /**
    IOCx registers 
    */
    IOCAP = 0x0;
    IOCAN = 0x1;
    IOCAF = 0x0;
    IOCWP = 0x0;
    IOCWN = 0x0;
    IOCWF = 0x0;
    IOCBP = 0x0;
    IOCBN = 0x0;
    IOCBF = 0x0;
    IOCCP = 0x0;
    IOCCN = 0x0;
    IOCCF = 0x0;
    IOCEP = 0x0;
    IOCEN = 0x0;
    IOCEF = 0x0;

    IO_RA0_SetInterruptHandler(IO_RA0_DefaultInterruptHandler);

    // Enable PIE0bits.IOCIE interrupt 
    PIE0bits.IOCIE = 1; 
}
  
void PIN_MANAGER_IOC(void)
{
    // interrupt on change for pin IO_RA0
    if(IOCAFbits.IOCAF0 == 1)
    {
        IO_RA0_ISR();  
    }
}
   
/**
   IO_RA0 Interrupt Service Routine
*/
void IO_RA0_ISR(void) {

    // Add custom IO_RA0 code

    // Call the interrupt handler for the callback registered at runtime
    if(IO_RA0_InterruptHandler)
    {
        IO_RA0_InterruptHandler();
    }
    IOCAFbits.IOCAF0 = 0;
}

/**
  Allows selecting an interrupt handler for IO_RA0 at application runtime
*/
void IO_RA0_SetInterruptHandler(void (* InterruptHandler)(void)){
    IO_RA0_InterruptHandler = InterruptHandler;
}

/**
  Default interrupt handler for IO_RA0
*/
void IO_RA0_DefaultInterruptHandler(void){
    // add your IO_RA0 interrupt custom code
    // or set custom function using IO_RA0_SetInterruptHandler()
    PORTCbits.RC7 = 0;
}
/**
 End of File
*/