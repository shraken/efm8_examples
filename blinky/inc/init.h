/** @file init.h
 *  @brief Function prototypes for the init routines.
 *
 */
 
#ifndef _C8051F380_INIT_H
#define _C8051F380_INIT_H

#include <compiler_defs.h>
#include <C8051F380_defs.h>
#include <c8051f3xx.h>
#include <globals.h>

/* internal OSC mode for low 
   power testing enum 
*/
typedef enum _OSC_MODES {
    OSC_MODE_0 = 0,
    OSC_MODE_1,
    OSC_MODE_2,
    OSC_MODE_3,
} OSC_MODES;

void Oscillator_Init(int mode);
void Port_Init(void);

#endif