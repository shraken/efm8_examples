/**
 * @file init.c
 * @brief Init routines
 *
 */

#include <init.h>

void Oscillator_Init(int mode)
{
    RSTSRC = 0x04;
    switch (mode) {
        case OSC_MODE_0:
            OSCICN = 0x80;
            break;
        
        case OSC_MODE_1:
            OSCICN = 0x81;
            break;
        
        case OSC_MODE_2:
            OSCICN = 0x82;
            break;
        
        case OSC_MODE_3:
            OSCICN = 0x83;
            break;
        
        default:
            break;
    }
}

void Port_Init(void)
{
    // Disable crossbar support for pins requiring
    // analog out/in functionality

    XBR0 = 0x03;                        // UART0 TX and RX pins enabled
    XBR1 = 0x40;                        // Enable crossbar and weak pull-ups

    P0MDOUT |= 0x1D;                    // Enable TX0 as a push-pull output
}