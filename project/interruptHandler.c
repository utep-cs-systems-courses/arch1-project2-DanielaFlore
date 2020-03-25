#include <msp430.h>
#include "stateMachine.h"
#include "led.h"
#include "switches.h"

// handles interrupt from buttos

void __interrupt_vec(PORT2_VECTOR) Port_2(){
  //checks if button caused interrupt, if so clear pending sw interrupt
  if (P2IFG & SWITCHES) {  

    P2IFG &= ~SWITCHES; 

    switch_interrupt_handler();

  }

}
void __interrupt_vec(WDT_VECTOR) WDT(){// 250 interrupts/sec
  sm_update_led();
  led_update();
}
