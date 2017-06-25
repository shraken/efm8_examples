/**
 * @file main.c
 * @brief Main block
 *
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <gpio.h>
#include <init.h>

#define LED_PIN GPIO_P2_0
//#define LED_PIN GPIO_P1_7
//#define LED_PIN GPIO_P1_6

void UART0_Init(void);
void Port_Init(void);
void delay (unsigned int time);

void blinky_gpio_init(void)
{
    gpio_set_pin_mode(LED_PIN, GPIO_MODE_PUSH_PULL);
    gpio_set_pin_value(LED_PIN, GPIO_VALUE_HIGH);
}

void main (void) 
{
   unsigned int main_count = 0;

   PCA0MD  &= ~0x40;

   // Initialize Oscillator
   Oscillator_Init(OSC_MODE_3);                  

   Port_Init();                        // Initialize Port I/O
   blinky_gpio_init();

   EA = 1;
   while (1)
   {  
      gpio_set_pin_value(LED_PIN, GPIO_VALUE_HIGH);
      delay(1000);
      gpio_set_pin_value(LED_PIN, GPIO_VALUE_LOW);
      delay(1000);
    }
}

void delay (unsigned int time)
{
   TCON    &= ~0x30;                   // stop T0 & clear flag
   TMOD    &= ~0x0F;                   // clear T0 nibble of TMOD
   TMOD    |= 0x01;                    // T0 16 bit counter mode
   CKCON   |= 0x04;                    // T0 uses SYSCLK
   // set T0 using time
   time = -time;
   TL0      = (unsigned char)(time & 0x00FF);
   TH0      = (unsigned char)(time >> 8);    
   //switch to low freq oscillator
   OSCLCN   = 0x80;                    // LFO is 10 kHz
   CLKSEL   = 0x04;                    // Switch to LFO
   TCON    |= 0x10;                    // enable T0
   while (!TF0);                        // wait for TOF
   TCON    &= ~0x30;                   // stop T0 & clear flag
   OSCICN    =  0x83;                  // enable 24.5 MHz int osc
   CLKSEL    = 0x00;                   // use int osc
}

//-----------------------------------------------------------------------------
// Interrupt Service Routines
//-----------------------------------------------------------------------------
// T0ISR ()
//-----------------------------------------------------------------------------
void T0_ISR (void) interrupt 1
{   
   OSCICN    =  0x83;                  // enable 24.5 MHz int osc
   while ((OSCICN & 0x40) == 0);       // wait for lock bit
   CLKSEL    = 0x00;                   // use int osc
   TCON   &= ~0x10;                    // stop timer T0   
   IE     &= ~0x02;                    // disable T0 interrupt 
}