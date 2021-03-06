#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "stateMachine.h"
#include "buzzer.h"
char switch_state_down, switch_state_changed;
char sw1_dwn, sw2_dwn, sw3_dwn, sw4_dwn;
char ledMode = 0, again = 0;


static char switch_update_interrupt_sense(){
  char p2val = P2IN;

  //update switch interrupt to detect changes from current button
  P2IES |= (p2val & SWITCHES);//if switch is (up) just got pushed
  P2IES &= (p2val | ~SWITCHES);//if switch down now let go of it
  return p2val;
}

void switch_init(){
  P2REN |= SWITCHES;//enables registers
  P2IE = SWITCHES;//enable interrupt
  P2OUT |= SWITCHES;//pull-ups
  P2DIR &= ~SWITCHES;//set switches
  switch_update_interrupt_sense();
  led_update();
}

void switch_interrupt_handler(){
  char p2val =switch_update_interrupt_sense();
  sw1_dwn = (p2val & SW1) ? 0: 1;//p2.1
  sw2_dwn = (p2val & SW2) ? 0: 1;//p2.2
  sw3_dwn = (p2val & SW3) ? 0: 1;//p2.3
  sw4_dwn = (p2val & SW4) ? 0: 1;//p2.4

  if(sw1_dwn){
    ledMode = 1; again++;
  }
  if(sw2_dwn){
    ledMode = 2; again++; songs(1);
  }
  if(sw3_dwn){
    ledMode = 3; again++;
  }
  if(sw4_dwn){
    ledMode = 4; again++;
  }
    switch_state_changed = 1;
}

