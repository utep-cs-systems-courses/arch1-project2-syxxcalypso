#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "sound.h"
#include "delay.h"

void __interrupt_vec(PORT2_VECTOR) switch_isr(){
  if (P2IFG & SWITCHES) {         // did a button cause this interrupt?
    P2IFG &= ~SWITCHES;           // clear pending sw interrupts
    handle_switch_irq(); // single handler for all switches
  }
}

static char switch_state(){
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P1IES |= (p2val & SWITCHES);	/* if switch up, sense down */
  P1IES &= (p2val | ~SWITCHES);	/* if switch down, sense up */
  return p2val;
}

void init_switches()			/* setup switch */
{  
  P2REN |= SWITCHES;		/* enables resistors for switches */
  P2IE = SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */
  switch_state();
  //led_update();
}


void handle_switch_irq(){
  char state = switch_state();
  state = (~state | 240) - 240;        // Get inverted nibble state and remove status flags

  switch(state) {
      case SW1:
          update_leds();
          break;
      case SW2:
          set_leds(0);
          break;
      case SW3:
        set_buzzer(400);
        __delay_cycles(1*8000000);
        set_buzzer(500);
        __delay_cycles(1*8000000);
        set_buzzer(600);
        __delay_cycles(1*8000000);
        set_buzzer(500);
        __delay_cycles(1*8000000);
        set_buzzer(400);
        __delay_cycles(1*8000000);
        set_buzzer(200);
        __delay_cycles(4*8000000);
        set_buzzer(400);
        __delay_cycles(1*8000000);
        set_buzzer(500);
        __delay_cycles(1*8000000);
        set_buzzer(600);
        __delay_cycles(1*8000000);
        set_buzzer(200);
        __delay_cycles(1*8000000);
        set_buzzer(600);
        __delay_cycles(1*8000000);
        set_buzzer(300);
        __delay_cycles(1*8000000);
        set_buzzer(0);
          break;
      case SW4: // Ensure stop
          set_buzzer(0);
          break;
      default:
          break;
  }
}
