#ifndef BUTTONS_H
#define BUTTONS_H

#define SW1 BIT0
#define SW2 BIT1
#define SW3 BIT2
#define SW4 BIT3
#define BUTTONS (SW1 | SW2 | SW3 | SW4)

void buttons_init();
char buttons_check();

#endif
