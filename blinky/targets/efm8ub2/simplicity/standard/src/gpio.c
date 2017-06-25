/**
 * @file gpio.c
 * @brief Simple GPIO wrapper for manipulation
 *
 */
 
#include <stdio.h>
#include <stdint.h>
#include <globals.h>
#include <gpio.h>

/** @brief Sets the pin value to high or low state.
  *
  *  @param pin Encoded pin value from gpio_drive_pins.
  *  @param value High or Low enum enumeration.
  *  @return error_t enum indicating success or error.
 */
error_t gpio_set_pin_value(gpio_pin pin, gpio_value value)
{
    gpio_major_pin pin_major;
    gpio_minor_pin pin_minor;

    // use bitmask and shift operationt to extract
    // the major and minor positions
    pin_major = ((pin & GPIO_MAJOR_MASK) >> 3);
    pin_minor = (pin & GPIO_MINOR_MASK);
    
    switch (pin_major)
    {
        case GPIO_MAJOR_PORT0:
            //P0 ^= (-value ^ pin_minor) & (1 << pin_minor);
            P0 = (value == GPIO_VALUE_HIGH) ? (P0 | (1 << pin_minor)) : (P0 & ~(1 << pin_minor));
            break;
        
        case GPIO_MAJOR_PORT1:
            //P1 ^= (-value ^ pin_minor) & (1 << pin_minor);
            P1 = (value == GPIO_VALUE_HIGH) ? (P1 | (1 << pin_minor)) : (P1 & ~(1 << pin_minor));
            break;
        
        case GPIO_MAJOR_PORT2:
            //P2 ^= (-value ^ pin_minor) & (1 << pin_minor);
            P2 = (value == GPIO_VALUE_HIGH) ? (P2 | (1 << pin_minor)) : (P2 & ~(1 << pin_minor));
            break;
        
        case GPIO_MAJOR_PORT3:
            //P3 ^= (-value ^ pin_minor) & (1 << pin_minor);
            P3 = (value == GPIO_VALUE_HIGH) ? (P3 | (1 << pin_minor)) : (P3 & ~(1 << pin_minor));
            break;
        
        case GPIO_MAJOR_PORT4:
            //P4 ^= (-value ^ pin_minor) & (1 << pin_minor);
            P4 = (value == GPIO_VALUE_HIGH) ? (P4 | (1 << pin_minor)) : (P4 & ~(1 << pin_minor));
            break;
        
        // bad input, fail gracefully
        default:
            return E_INDEX_OUT_BOUND;
            break;
    }
    
    // otherwise, success
    return E_SUCCESS;
}

/** @brief Sets the pin mode to open-drain or push-pull.
  *
  *  @param pin Encoded pin value from gpio_drive_pins
  *  @param mode Open Drain or Push Pull enumeration
  *  @return error_t enum indicating success or error.
 */
error_t gpio_set_pin_mode(gpio_pin pin, gpio_mode mode)
{
    gpio_major_pin pin_major;
    gpio_minor_pin pin_minor;

    // use bitmask and shift operationt to extract
    // the major and minor positions
    pin_major = ((pin & GPIO_MAJOR_MASK) >> 3);
    pin_minor = (pin & GPIO_MINOR_MASK);
    
    if (mode == GPIO_MODE_OPEN_DRAIN) {
        switch (pin_major)
        {
            case GPIO_MAJOR_PORT0:
                P0MDOUT &= ~(1 << pin_minor);
                P0MDIN &= ~(1 << pin_minor);
                break;
            
            case GPIO_MAJOR_PORT1:
                P1MDOUT &= ~(1 << pin_minor);
                P1MDIN &= ~(1 << pin_minor);
                break;
            
            case GPIO_MAJOR_PORT2:
                P2MDOUT &= ~(1 << pin_minor);
                P2MDIN &= ~(1 << pin_minor);
                break;
            
            case GPIO_MAJOR_PORT3:
                P3MDOUT &= ~(1 << pin_minor);
                P3MDIN &= ~(1 << pin_minor);
                break;
            
            case GPIO_MAJOR_PORT4:
                P4MDOUT &= ~(1 << pin_minor);
                P4MDIN &= ~(1 << pin_minor);
                break;
            
            default:
                return 0;
                break;
        }
    } else {
        switch (pin_major)
        {
            case GPIO_MAJOR_PORT0:
                P0MDOUT |= (1 << pin_minor);
                P0MDIN |= (1 << pin_minor);
                break;
            
            case GPIO_MAJOR_PORT1:
                P1MDOUT |= (1 << pin_minor);
                P1MDIN |= (1 << pin_minor);
                break;
            
            case GPIO_MAJOR_PORT2:
                P2MDOUT |= (1 << pin_minor);
                P2MDIN |= (1 << pin_minor);
                break;
            
            case GPIO_MAJOR_PORT3:
                P3MDOUT |= (1 << pin_minor);
                P3MDIN |= (1 << pin_minor);
                break;
            
            case GPIO_MAJOR_PORT4:
                P4MDOUT |= (1 << pin_minor);
                P4MDIN |= (1 << pin_minor);
                break;
            
            default:
                return 0;
                break;
        }
    }
    
    // otherwise, success
    return E_SUCCESS;
}

int gpio_get_pin_value(gpio_pin pin)
{
    uint8_t pin_value;
    gpio_major_pin pin_major;
    gpio_minor_pin pin_minor;
    
    // use bitmask and shift operationt to extract
    // the major and minor positions
    pin_major = ((pin & GPIO_MAJOR_MASK) >> 3);
    pin_minor = (pin & GPIO_MINOR_MASK);
    
    switch (pin_major)
    {
        case GPIO_MAJOR_PORT0:
            pin_value = P0 & (1 << pin_minor);
            break;
        
        case GPIO_MAJOR_PORT1:
            pin_value = P1 & (1 << pin_minor);
            break;
        
        case GPIO_MAJOR_PORT2:
            pin_value = P2 & (1 << pin_minor);
            break;
        
        case GPIO_MAJOR_PORT3:
            pin_value = P3 & (1 << pin_minor);
            break;
        
        case GPIO_MAJOR_PORT4:
            pin_value = P4 & (1 << pin_minor);
            break;
       
        default:
            pin_value = 0;
            break;
    }
    
    // otherwise, success
    return pin_value;
}