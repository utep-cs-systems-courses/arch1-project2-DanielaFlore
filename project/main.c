#include <msp430.h>
#include "timerLib/libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

void main(){
  configureClocks();
  buzzer_init();
  led_init();
  switch_init();
  enableWDTInterrupts();

  or_sr(0x18);

}
