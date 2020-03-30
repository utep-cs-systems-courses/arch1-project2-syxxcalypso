#ifndef switches_included
#define switches_included

#define SW1 BIT0        /* switch1 is p2.0 */
#define SW2 BIT1        /* switch1 is p2.1 */
#define SW3 BIT2        /* switch1 is p2.2 */
#define SW4 BIT3        /* switch1 is p2.3 */
#define SWITCHES (SW1|SW2|SW3|SW4)		/* all switches */

void init_switches();

#endif // included
