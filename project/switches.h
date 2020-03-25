#ifndef switches_included

#define switches_included



#define SW1 BIT0 /*switch one is p2.1*/

#define SW2 BIT1 //switch two is p2.2

#define SW3 BIT2 //switch three is p2.3

#define SW4 BIT3 //switch four is p2.4

#define SWITCHES (SW1|SW2|SW3|SW4)//initialize all switches



void switch_init();

void switch_interrupt_handler();



extern char switch_state_down, switch_state_changed; /* effectively boolean */
extern char sw1_dwn, sw2_dwn, sw3_dwn, sw4_down, ledMode, again;

#endif // included
