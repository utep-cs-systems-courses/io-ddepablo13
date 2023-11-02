#ifndef LED_CONTROL_H
#define LED_CONTROL_H

/**
 * Initialize the LED control.
 */
void init_leds();

/**
 * Set the LEDs based on a bitmask.
 *
 * @param led_mask The bitmask to set LEDs. For example, 0x01 sets the first LED on, and 0x02 sets the second LED on.
 */
void set_leds(unsigned char led_mask);

/**
 * Set the brightness of the LEDs.
 *
 * @param brightness The brightness level.
 */
void set_led_brightness(unsigned char brightness);

#endif // LED_CONTROL_H
