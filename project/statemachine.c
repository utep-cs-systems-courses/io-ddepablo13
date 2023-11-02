#include "state_machine.h"
#include "led_control.h"
#include "sound.h"

// State Enumeration
enum States {
  STATE1,
  STATE2,
  STATE3,
  STATE4
};

extern void transition_state_3();  // Declare the assembly function

static enum States current_state = STATE1; // Initial State

void init_buttons() {
  P2DIR &= ~0x0F; // P2.0 to P2.3 as input
  P2REN |= 0x0F;  // Enable pull-up/down resistors
  P2OUT |= 0x0F;  // Pull-up
}

void check_buttons() {
  unsigned char buttons = (P2IN & 0x0F); // Read buttons

  // Assume active low buttons
  if (!(buttons & 0x01)) {
    current_state = STATE1;
  } else if (!(buttons & 0x02)) {
    current_state = STATE2;
  } else if (!(buttons & 0x04)) {
    current_state = STATE3;
  } else if (!(buttons & 0x08)) {
    current_state = STATE4;
  }
}

void transition_states() {
  check_buttons(); // Check if any button is pressed

  switch (current_state) {
    case STATE1:
      set_leds(0x01); // Turn on the first LED
      generate_sound(0x01); // Play the first note
      break;

    case STATE2:
      set_leds(0x02); // Turn on the second LED
      generate_sound(0x02); // Play the second note
      break;

    case STATE3:
      transition_state_3();  // Assembly function to handle this state
      break;

    case STATE4:
      set_leds(0x03); // Turn on both LEDs
      generate_sound(0x03); // Play the third note
      break;
  }
}
