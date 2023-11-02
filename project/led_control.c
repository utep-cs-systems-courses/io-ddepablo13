#include <msp430.h>
#include "led_control.h"

void set_leds(unsigned char led_mask) {
  // Assuming LEDs are connected to P1.0 and P1.1
  P1OUT &= ~0x03;        // Clear the LED bits
  P1OUT |= (led_mask & 0x03); // Set the LEDs based on led_mask
}

void set_led_brightness(unsigned char brightness) {
  // Assuming use of Timer_A for PWM brightness control
  // Configure Timer_A for LED brightness (PWM)
  TACTL |= TASSEL_2 + MC_1; // Timer A control: SMCLK, Up mode
  TACCR0 = 255;             // Set Timer A period (PWM Period)
  TACCR1 = brightness;      // Timer A capture compare value (Duty cycle)

  // Configure PWM output on P1.0 (assuming it's connected here)
  P1DIR |= BIT0;  // P1.0 output
  P1SEL |= BIT0;  // P1.0 options select
  TACCTL1 = OUTMOD_7; // TACCR1 reset on CCR0
}

void init_leds() {
  P1DIR |= 0x03;  // P1.0 and P1.1 as output
  P1OUT &= ~0x03; // Initially set to low
}
