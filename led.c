#include <msp430.h>
#include "led.h"
#include "switches.h"

// prototype to assemble the machines
extern void update();

void init_leds(){
  P1DIR |= LEDS;		// bits attached to leds are output
  P1OUT = 0;            // Ensure LEDs are off
}

void update_leds(){      // State Machine
	// call to assembly the machines
	update();
/*
    switch(P1OUT){      // Current state is encoded in P1OUT
    case LED_RED:       // Current state is red
        set_red(0);
        set_green(1);    // transition state to green
        break;
    case LED_GREEN:     // Current state is green
        set_green(0);
        set_red(1);      // transition state to red
        break;
    default:            // Current state is off
        set_green(1);
    }
*/
}

void set_red(char state){
    switch(state){
    case 0:
        P1OUT &= ~LED_RED;
        break;
    default:
        P1OUT |= LED_RED;
        break;
    }
}

void set_green(char state){
    switch(state){
    case 0:
        P1OUT &= ~LED_GREEN;
        break;
    default:
        P1OUT |= LED_GREEN;
        break;
    }
}

void set_leds(char state){
    set_red(state);
    set_green(state);
}
