// Jennifer Harrison
// 
#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "sound.h"

void main(void){
  configureClocks();
  init_switches();
  init_leds();
  init_buzzer();
  or_sr(0x18);  // CPU off, GIE on
} 
