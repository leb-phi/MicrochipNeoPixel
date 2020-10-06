/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC18F46K42
        Driver Version    :  2.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
        MPLAB 	          :  MPLAB X 4.15	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA2 procedures
#define RA2_SetHigh()               do { LATAbits.LATA2 = 1; } while(0)
#define RA2_SetLow()                do { LATAbits.LATA2 = 0; } while(0)
#define RA2_Toggle()                do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define RA2_GetValue()              PORTAbits.RA2
#define RA2_SetDigitalInput()       do { TRISAbits.TRISA2 = 1; } while(0)
#define RA2_SetDigitalOutput()      do { TRISAbits.TRISA2 = 0; } while(0)
#define RA2_SetPullup()             do { WPUAbits.WPUA2 = 1; } while(0)
#define RA2_ResetPullup()           do { WPUAbits.WPUA2 = 0; } while(0)
#define RA2_SetAnalogMode()         do { ANSELAbits.ANSELA2 = 1; } while(0)
#define RA2_SetDigitalMode()        do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set RA3 procedures
#define RA3_SetHigh()               do { LATAbits.LATA3 = 1; } while(0)
#define RA3_SetLow()                do { LATAbits.LATA3 = 0; } while(0)
#define RA3_Toggle()                do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define RA3_GetValue()              PORTAbits.RA3
#define RA3_SetDigitalInput()       do { TRISAbits.TRISA3 = 1; } while(0)
#define RA3_SetDigitalOutput()      do { TRISAbits.TRISA3 = 0; } while(0)
#define RA3_SetPullup()             do { WPUAbits.WPUA3 = 1; } while(0)
#define RA3_ResetPullup()           do { WPUAbits.WPUA3 = 0; } while(0)
#define RA3_SetAnalogMode()         do { ANSELAbits.ANSELA3 = 1; } while(0)
#define RA3_SetDigitalMode()        do { ANSELAbits.ANSELA3 = 0; } while(0)

// get/set RB1 procedures
#define RB1_SetHigh()               do { LATBbits.LATB1 = 1; } while(0)
#define RB1_SetLow()                do { LATBbits.LATB1 = 0; } while(0)
#define RB1_Toggle()                do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define RB1_GetValue()              PORTBbits.RB1
#define RB1_SetDigitalInput()       do { TRISBbits.TRISB1 = 1; } while(0)
#define RB1_SetDigitalOutput()      do { TRISBbits.TRISB1 = 0; } while(0)
#define RB1_SetPullup()             do { WPUBbits.WPUB1 = 1; } while(0)
#define RB1_ResetPullup()           do { WPUBbits.WPUB1 = 0; } while(0)
#define RB1_SetAnalogMode()         do { ANSELBbits.ANSELB1 = 1; } while(0)
#define RB1_SetDigitalMode()        do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()               do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()                do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()                do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()              PORTCbits.RC3
#define RC3_SetDigitalInput()       do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()      do { TRISCbits.TRISC3 = 0; } while(0)
#define RC3_SetPullup()             do { WPUCbits.WPUC3 = 1; } while(0)
#define RC3_ResetPullup()           do { WPUCbits.WPUC3 = 0; } while(0)
#define RC3_SetAnalogMode()         do { ANSELCbits.ANSELC3 = 1; } while(0)
#define RC3_SetDigitalMode()        do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()               do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()                do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()                do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()              PORTCbits.RC4
#define RC4_SetDigitalInput()       do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()      do { TRISCbits.TRISC4 = 0; } while(0)
#define RC4_SetPullup()             do { WPUCbits.WPUC4 = 1; } while(0)
#define RC4_ResetPullup()           do { WPUCbits.WPUC4 = 0; } while(0)
#define RC4_SetAnalogMode()         do { ANSELCbits.ANSELC4 = 1; } while(0)
#define RC4_SetDigitalMode()        do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set SW1 aliases
#define SW1_TRIS                 TRISDbits.TRISD0
#define SW1_LAT                  LATDbits.LATD0
#define SW1_PORT                 PORTDbits.RD0
#define SW1_WPU                  WPUDbits.WPUD0
#define SW1_OD                   ODCONDbits.ODCD0
#define SW1_ANS                  ANSELDbits.ANSELD0
#define SW1_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define SW1_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define SW1_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define SW1_GetValue()           PORTDbits.RD0
#define SW1_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define SW1_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define SW1_SetPullup()          do { WPUDbits.WPUD0 = 1; } while(0)
#define SW1_ResetPullup()        do { WPUDbits.WPUD0 = 0; } while(0)
#define SW1_SetPushPull()        do { ODCONDbits.ODCD0 = 0; } while(0)
#define SW1_SetOpenDrain()       do { ODCONDbits.ODCD0 = 1; } while(0)
#define SW1_SetAnalogMode()      do { ANSELDbits.ANSELD0 = 1; } while(0)
#define SW1_SetDigitalMode()     do { ANSELDbits.ANSELD0 = 0; } while(0)

// get/set SW2 aliases
#define SW2_TRIS                 TRISDbits.TRISD1
#define SW2_LAT                  LATDbits.LATD1
#define SW2_PORT                 PORTDbits.RD1
#define SW2_WPU                  WPUDbits.WPUD1
#define SW2_OD                   ODCONDbits.ODCD1
#define SW2_ANS                  ANSELDbits.ANSELD1
#define SW2_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define SW2_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define SW2_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define SW2_GetValue()           PORTDbits.RD1
#define SW2_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define SW2_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define SW2_SetPullup()          do { WPUDbits.WPUD1 = 1; } while(0)
#define SW2_ResetPullup()        do { WPUDbits.WPUD1 = 0; } while(0)
#define SW2_SetPushPull()        do { ODCONDbits.ODCD1 = 0; } while(0)
#define SW2_SetOpenDrain()       do { ODCONDbits.ODCD1 = 1; } while(0)
#define SW2_SetAnalogMode()      do { ANSELDbits.ANSELD1 = 1; } while(0)
#define SW2_SetDigitalMode()     do { ANSELDbits.ANSELD1 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/