#include <msp430.h>
#include "buttons.h"

void buttons_init() {
  P2REN |= BUTTONS;  // Enable resistors for buttons
  P2IE |= BUTTONS;   // Enable interrupts for buttons
  P2OUT |= BUTTONS;  // Pull-up resistors for buttons
  P2DIR &= ~BUTTONS; // Set buttons as input
}
