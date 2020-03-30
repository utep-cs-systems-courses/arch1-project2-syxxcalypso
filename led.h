#ifndef led_included
#define  led_included

#include <msp430.h>

#define LED_GREEN BIT0             // P1.0
#define LED_RED BIT6               // P1.6
#define LEDS (BIT0 | BIT6)

void init_leds();		/* initialize LEDs */
void update_leds();		/* update leds */
void set_red(char state);
void set_green(char state);
void set_leds(char state);

#endif
