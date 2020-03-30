#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "sound.h"
#include "delay.h"

void main(void){
  configureClocks();
  init_TA1();
  __enable_interrupt();
  init_switches();
  init_leds();
  init_buzzer();
  or_sr(0x18);  // CPU off, GIE on
} 
