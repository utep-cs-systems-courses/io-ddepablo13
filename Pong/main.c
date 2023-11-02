#include <msp430.h>
#include "led.h"
#include "buttons.h"
#include "statemachine.h"

void main(void) {
  WDTCTL = WDTPW + WDTHOLD; // Stop WDT

  led_init();         // Initialize LEDs
  buttons_init();     // Initialize buttons

  lcd.begin();        // Initialize LCD
  lcd.setRotation(0); // Set rotation to 0 (landscape)

  __enable_interrupt(); // Enable interrupt

  while(1) {
    advance_state(buttons_check()); // Check buttons and advance state
    __delay_cycles(1000);
  }
}
