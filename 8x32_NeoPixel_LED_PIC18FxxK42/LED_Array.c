
/**
  Company:
    Microchip Technology Inc.

  File Name:
 LED_Array.c

  Summary:
 * 8x32 LED array driver.

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
 
 
#include "mcc_generated_files/mcc.h"
#include <xc.h>
#include "LED_Array.h"

#define BrightnessMAX   250

void loadBuffer(char *userText) {
    //Load the userText char string into individual locations in the WriteBuffer array
    for (CNT = 0; CNT < 256; CNT++) {
        WriteBuffer[CNT] = *userText++;
    }
}

void writeLEDArray(void) {
    //Write WS2812 LEDS
    if (ColorFontGREEN>BrightnessMAX ) ColorFontGREEN = BrightnessMAX ;
    if (ColorFontRED>BrightnessMAX ) ColorFontRED = BrightnessMAX ;
    if (ColorFontBLUE>BrightnessMAX ) ColorFontBLUE = BrightnessMAX ;
    if (ColorBackGREEN>BrightnessMAX ) ColorBackGREEN = BrightnessMAX ;
    if (ColorBackRED>BrightnessMAX ) ColorBackRED = BrightnessMAX ;
    if (ColorBackBLUE>BrightnessMAX ) ColorBackBLUE = BrightnessMAX ;
    
    
      for (CNT = 0; CNT < 256; ++CNT) {
        StateTest = (WriteArray[CNT]); // Test AsciiBitMap bitmap for font or background
        if (StateTest == 1) { //Write characters
            DMAArray[(CNT*3)] = ColorFontGREEN; //Green
            DMAArray[(CNT*3)+ 1] = ColorFontRED; //Red
            DMAArray[(CNT*3) + 2] = ColorFontBLUE; //Blue 
        }
        if (StateTest == 0) { //Write background color
            DMAArray[(CNT*3)] = ColorBackGREEN; //Green
            DMAArray[(CNT*3)+ 1] = ColorBackRED; //Red
            DMAArray[(CNT*3) + 2] = ColorBackBLUE; //Blue 
        }
    }
    
    DMA1CON0bits.SIRQEN = 1;   
    
}

void loadLEDArray(void) { //Store, shift and update array
    //Load FormatArray with WriteArray to make updates   
    for (CNT = 0; CNT < 256; ++CNT) {
        FormatArray[CNT] = WriteArray[CNT]; //Store current state of write array. Which will later be modified and updated. 
    }
    ArrayIndex = 0;
    for (AI = 0; AI <= 30; AI++) { //Shift all characters over one column
        RowStep = 15;
        for (CNT = 0; CNT < 8; CNT++) {
            WriteArray[ArrayIndex + RowStep] = FormatArray[ArrayIndex];
            RowStep = RowStep - 2;
            ++ArrayIndex;
        }
    }
    for (CNT = 0; CNT < 8; CNT++) { //Add new character values from AsciiBitMap to column one of WriteArray

        if (WriteBuffer[BufferInc] == 32) {
            WriteArray[CNT] = AsciiBitMap[0][LI]; //Check for SPACE and end of word.
            ++LI;
            WriteComplete = 1; //End of word. Set flag for TMR1 interrupt user code to banner switch
        }

        if ((WriteBuffer[BufferInc] >= 33) && (WriteBuffer[BufferInc] <= 126)) { //Test for defined characters (AsciiBitMap). 
            WriteArray[CNT] = AsciiBitMap[WriteBuffer[BufferInc] - 32][LI]; //Move AsciiBitMap to format array
            ++LI;
            WriteComplete = 0;
        } else {
            WriteArray[CNT] = AsciiBitMap[0][LI]; //Any character which is not defined will print as a space
            ++LI;
        }
    }
    NOP();
    if (LI >= 48) { //6*8=48 AsciiBitMap// characters complete
        LI = 0;
        BufferInc++; //Move to next characters in buffer
    }
    if (WriteBuffer[BufferInc] == 0) { //Check for end of userText. If end reset BufferInc to loop text. 
        BufferInc = 0;
    }
}

void clearLEDArray(void) {
    for (CNT = 0; CNT < 256; ++CNT) {
        SPI1TXB = 0;
        while (!SPI1STATUSbits.TXBE);
    }
}




/**
 End of File
 */
