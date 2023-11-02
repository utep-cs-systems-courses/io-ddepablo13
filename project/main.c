#include <msp430.h>
#include "libTimer.h"
#include "state_machine.h"
#include "led_control.h"
#include "sound.h"

int main(void) {
  // Setup
  WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer
  configureClocks(); // Provided by libTimer
  init_leds(); // Initialize LEDs
  init_sounds(); // Initialize sounds

  enableWDTInterrupts(); // Enable timer interrupts

  or_sr(0x18); // CPU off, GIE on
}
