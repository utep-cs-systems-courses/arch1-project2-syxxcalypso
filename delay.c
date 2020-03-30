#include <msp430.h>
/*
unsigned long TA1OC;                     // Current oscillation counter

void init_TA1(){
    TA1CCR0 = 0;
    TA1CCTL0 |= CCIE;                    // Enable Timer IRQs
    TA1CTL = TASSEL_2 + ID_0 + MC_1;     // Use 4MHz internal clock
   // TA1CTL |= ID_0;                    // Disable clock-speed division
   // TA1CTL |= MC_1;                    // Count up to TA1CCR0+1
}

void delay_ms(unsigned int ms)
{
    TA1OC = 0;                          // Initialize oscillation counter
    TA1CCR0 = 999;                      // Establish CCR limit
                                        // (Starts from 0 to 999 for 1ms)
    while(TA1OC <= ms);
    TA1CCR0 = 0;                        // Stop TA1
}

// Timer ISR
void __interrupt_vec(TIMER0_A1_VECTOR) TA1ISR() { TA1OC++; }
*/

unsigned int OFCount;

void init_TA1(void)
{
    //Timer0_A3 Configuration
    TA1CCR0 = 0; //Initially, Stop the Timer
    TA1CCTL0 |= CCIE; //Enable interrupt for CCR0.
    TA1CTL = TASSEL_2 + ID_0 + MC_1; //Select SMCLK, SMCLK/1, Up Mode
}

void delay_msi(int ms)
{
    OFCount = 0; //Reset Over-Flow counter
    TA1CCR0 = 1000-1; //Start Timer, Compare value for Up Mode to get 1ms delay per loop
    //Total count = TACCR0 + 1. Hence we need to subtract 1.

    while(OFCount<=ms);

    TA1CCR0 = 0; //Stop Timer
}

//Timer ISR
void __interrupt_vec(TIMER0_A1_VECTOR) Timer_A_CCR0_ISR(void)
{
    OFCount++; //Increment Over-Flow Counter
}
