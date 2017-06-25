/** @file gpio.h
 *  @brief Function prototypes for the GPIO.
 */
 
#ifndef _C8051F380_GPIO_H
#define _C8051F380_GPIO_H

#include <compiler_defs.h>
#include <C8051F380_defs.h>
#include <globals.h>

// prototypes
error_t gpio_set_pin_value(gpio_pin pin, gpio_value value);
error_t gpio_set_pin_mode(gpio_pin pin, gpio_mode mode);
int gpio_get_pin_value(gpio_pin pin);

#endif