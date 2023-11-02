#ifndef LED_H
#define LED_H

#define LED_RED BIT0
#define LED_GREEN BIT6
#define LEDS (LED_RED | LED_GREEN)

extern char red_on, green_on;

void led_init();
void led_update();

#endif
