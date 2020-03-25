#include <msp430.h>
#include "stateMachine.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

// state variables
static enum {off=0, dim=1, bright=2} led_mode;
static char pwmCount = 0;

//slowly cycles through enum array with the help of modulus
void sm_slow_clock(){
  led_mode = (led_mode + 1) % 3;
}
//toggles red 
char toggle_red(){
  static char state = 0;

  switch (state) {
  case 0:
    red_on = 1;
    state = 1;
  case 1:
    red_on = 0;
    state = 0;
  }
  return 1;
}
//alternates between toggling red and green
void state_advance(){
  char changed = 0;
  changed = toggle_red();
  led_changed = changed;
  led_update();
}

void sm_update_led(){
  pwmCount = (pwmCount +1) % 3;
  char new_red_on, new_green_on;
  switch(ledMode){
  case 0:
    //starts with both lights on, no button pressed yet
    new_red_on = 1;
    new_green_on = 1;
    break;
  case 1:
    //green is on
    new_red_on = (again % 2);
    new_green_on = 0;
    buzzer_set_period(6000);
    break;
  case 2:
    //green dims
    new_red_on = 0;
    new_green_on = (pwmCount <1);
    break;
  case 3:
    //red is on
    new_red_on = 0;
    new_green_on = (again %2);
    buzzer_set_period(8000);
    break;
  case 4:
    //red dims
    new_red_on = (pwmCount < 1);
    new_green_on = 0;
    buzzer_set_period(9000);
    break;
  }
  if(red_on != new_red_on || green_on != new_green_on){
    red_on = new_red_on;
    green_on = new_green_on;
    led_changed = 1;
  }
}

