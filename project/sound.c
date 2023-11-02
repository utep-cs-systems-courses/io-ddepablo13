#include <msp430.h>
#include "libTimer.h"
#include "sound.h"

void generate_sound(unsigned char note) {
  // Configure Timer A using libTimer
  configureTimerA();

  // Set Timer A CCR0 and CCR1
  timerASetPeriod(255);            // Equivalent to TACCR0 = 255
  timerASetCCR1(note);             // Equivalent to TACCR1 = note

  // Start Timer
  timerAUpMode();                  // Equivalent to TACTL |= TASSEL_2 + MC_1

  // Configure the output pin for Timer A (assume P1.2)
  P1DIR |= BIT2;
  P1SEL |= BIT2;

  // Connect Timer A output to pin (if libTimer doesn't do this)
  TACCTL1 = OUTMOD_7;              // TACCR1 reset/set
}

void stop_sound() {
  // Stop Timer using libTimer
  timerAStop();                    // Equivalent to TACTL &= ~MC_1
  P1DIR &= ~BIT2;                  // P1.2 as input to stop the speaker
}

void init_sound() {
  // Initialize the sound system (and maybe timer)
  P1DIR &= ~BIT2;                  // Initially set P1.2 as input
}
