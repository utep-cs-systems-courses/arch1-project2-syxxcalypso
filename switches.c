#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "sound.h"

char switch_state_down, switch_state_changed, sound_state_changed; /* effectively boolean */

static char switch_update_interrupt_sense(){
  char p1val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P1IES |= (p1val & SWITCHES);	/* if switch up, sense down */
  P1IES &= (p1val | ~SWITCHES);	/* if switch down, sense up */
  return p1val;
}

void switch_init()			/* setup switch */
{  
  P2REN |= SWITCHES;		/* enables resistors for switches */
  P2IE = SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */
  switch_update_interrupt_sense();
  led_update();
}


void switch_interrupt_handler(){
  char p2val = switch_update_interrupt_sense();
  if(!(p2val & SW1)){
      switch_state_down = 0;    // Button 1 will turn LED to Green
      state_advance();
  }

  else if(!(p2val & SW2)){     // Button 2 will turn LED to Red
    switch_state_down = 1;
    state_advance();
  }

  else if(!(p2val & SW3)){    // Button 3 will make the sounds with the noise
      buzzer_on();
  }
  else if(!(p2val & SW4)){      // Button will turn off sound
      buzzer_off();
  }
  switch_state_changed = 1;
  led_update();
}
