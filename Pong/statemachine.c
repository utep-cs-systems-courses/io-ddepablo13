#include <msp430.h>
#include <driverlib.h>  // MSP430 Driver Library, adjust path as needed
#include <stdio.h>
#include "statemachine.h"
#include "led.h"

static char state = 0;
static int red_score = 0;
static int green_score = 0;

void advance_state(char button_pressed) {
  char collision = red_on & green_on;

  switch (state) {
    case 0:
      if (button_pressed & SW1) state = 1;
      if (button_pressed & SW3) state = 2;
      red_on = 0; green_on = 0;
      break;

    case 1:
      if (button_pressed & SW3) state = 2;
      if (!collision) red_score++;
      red_on = 1; green_on = 0;
      break;

    case 2:
      if (button_pressed & SW1) state = 1;
      if (!collision) green_score++;
      red_on = 0; green_on = 1;
      break;
  }

  led_update();
  update_score();
}

void update_score() {
  char score_str[16];
  snprintf(score_str, sizeof(score_str), "Red: %d, Green: %d", red_score, green_score);
  LCD_clear();  // Clear the LCD, using Driver Library function
  LCD_showText(score_str);  // Write the score string to the LCD, using Driver Library function
}
