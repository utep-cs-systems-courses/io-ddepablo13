#include <msp430.h>
#include "led.h"

void led_init() {
  P1DIR |= LEDS; // Set LED pins to output
  P1OUT &= ~LEDS; // Turn off LEDs initially
}

void led_update() {
  P1OUT = (red_on ? LED_RED : 0) | (green_on ? LED_GREEN : 0);
}
