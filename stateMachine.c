#include <msp430.h>
#include "switches.h"
#include "sound.h"
#include "led.h"

// 0 = off 1 = on

unsigned char red_led_state = 0, leds_changed = 0;
unsigned char green_led_state = 0;

void red_state_machine(){
    red_led_state ^= 1;
    leds_changed = 1;
}

void green_state_machine(){
    leds_changed = 1;
    green_led_state = 1 - green_led_state;
}
void state_advance(){
    char led_Flag = 0;
    switch(led_Flag){
    case 0:
       red_state_machine();
       break;
    case 1:
        green_state_machine();
        break;
    }



}

