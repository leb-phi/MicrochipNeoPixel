# Introduction Microchip Example
'https://mplabxpress.microchip.com/mplabcloud/example/details/378?utm_campaign=8bithowto&utm_source=YouTube&utm_medium=VideoDescription&utm_term=&utm_content=MCU8_howto'

This project demonstrates how to create the custom protocol needed for controlling the WS2812 LEDs using the new PIC18FxxK42 microcontroller. This application also uses the 2 DMA modules on this device to drive the LEDs and also generate a set of waveforms without any CPU intervention.

# Application details

To control these LEDs we use the PWM, SPI and the CLC module. The PWM and SPI module are timed using the Timer2 as base. The PWM and the SPI modules are used to generate the logic '1' and '0' for the LEDs.The CLC module is used to create the custom protocol needed for these LEDs.

One of the DMA modules is used to feed data into the SPI module. This is the pattern data needed for the LEDs. The DMA module has built in capabilities to work with the SPI module without any intervention from the CPU. Once the pattern is created in memory, the DMA module can be used to export it to the SPI module.

The other DMA module is used to read a look up table stored in the flash memory and load the DAC module. The timing for this is controlled by the Timer0 module. Every time the timer overflows, the DMA will transfer a new value from the look up table into the DAC register.

All the peripherals in this application are initialized using the MPLAB Code Configurator (MCC).

# Pin details

The PIC18FxxK42 showcases Peripheral Pin Select (PPS). This allows the user to reconfigure digital inputs and outputs to multiple pins on the device.

    CLC3OUT - RB1 - This is to drive the LED panel - Selected using PPS
    DACOUT - RA2 - Waveform generator

# DMA Integration

The PIC18FxxK42 family of devices have 2 DMA modules. These DMA modules can read data from any memory on the device and write data only to the RAM. The source and destination addresses are configurable individually. The size of the DMA transaction is also progrmmable.

One of the most interesting features of the DMA module is internal hardware based triggers for transfers or abort conditions. A full list of the DMA triggers can be found in the device datasheet.

In this example as mentioned earlier, DMA1 is used to feed the data into the SPI buffer for the LEDs. You can observe in the dma1.c file that in the DMA1_Intialize() routine, we have set DMA1SIRQ = 21. This means that every time a byte has been transmitted out of the SPI transmit buffer, the SPI module will automatically trigger the DMA to transfer the next byte from memory into the transmit buffer. This eliminates the need for the CPU to monitor the SPI buffers and move data when it is empty.

Similarly DMA2 is used to transfer the data from a look up table stored in the flash memory to the DAC data register. The frequency of this transfer determines the frequency of the output waveform. In this case, we are using Timer0 to trigger the DMA module. Everytime Timer0 rolls over, it will automatically trigger DMA2 to transfer a byte into the DAC. You can notice this in the dma2.c file under the DMA2_Initialize() routine. Here DMA2SIRQ = 31 which is the code for Timer0. This eliminates the need for the CPU to keep track of the timing and transfer data.
# MCC Settings
## System Module

## SPI Module

## PWM Module

## CLC Module

## Timer2 Module

## Timer0 Module

## DAC Module

## Pin Manager

## Operation

    Make the required pin connections as mentioned in the Pin Details section.
    Program the device.
    Once program you will notice the text message scroll on the LED panel.
    The waveforms can be observed on pin RA2. The application scrolls through a sine wave, triangular wave and a sawtooth wave every 5 secs.

# Results
## LED Panel

The 8x32 NeoPixel panel should have the text scrolling. Note that the DMA module is being used to transmit the data to the LEDs and the CPU is idle during that period.
Waveforms on Oscilloscope

The oscilloscope connected to pin RA2 should cycle through the sine, triangular and sawtooth wave form every 5 seconds. Note that these waveforms are also being generated without any CPU interference.
Sine wave

## Triangular Wave

## Sawtooth Wave

# Useful Links

## Applikation Note
### Using the Configurable Logic Cell
http://ww1.microchip.com/downloads/en/AppNotes/00001606A.pdf
### Simple SRAM Buffering for Large LED Arrays
http://ww1.microchip.com/downloads/en/appnotes/00001890a.pdf

## PIC Used
https://www.microchip.com/wwwproducts/en/PIC18F47K42

## Youtube
https://www.youtube.com/watch?v=hHLMnJs87VE

## useful links
https://www.microchip.com/stellent/groups/SiteComm_sg/documents/DeviceDoc/en551260.pdf
