#include <msp430.h>
#include "timerLib/libTimer.h"
#include "buzzer.h"

void buzzer_init()
{
    /* 
       Direct timer A output "TA0.1" to P2.6.  
        According to table 21 from data sheet:
          P2SEL2.6, P2SEL2.7, anmd P2SEL.7 must be zero
          P2SEL.6 must be 1
        Also: P2.6 direction must be output
    */
    timerAUpmode();		/* used to drive speaker */
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7; 
    P2SEL |= BIT6;
    P2DIR = BIT6;		/* enable output to speaker (P2.6) */
}
//calls beat method if argument is one
void songs(char tune){
  switch(tune){
  case 1:
    beat();
    break;
  }
}
//stores sequence of beats
void beat(){
  /*
<<<<<<< HEAD
  int notes[10] = { 415, 293, 311, 277, 392, 392, 415, 293, 370, 293 };
=======
  */
  int notes[10] = { 415, 293, 311, 277, 392, 392, 415, 293, 370, 293 };
  //>>>>>>> e3ff364055419c08f41d47a0fd5ea24e9b847b92
  for(int i = 0;i<10;i++){
    buzzer_set_period(notes[i]);
    __delay_cycles(4000000);
  }
    buzzer_set_period(0);
  
}  
///////////////////////

void buzzer_set_period(short cycles) /* buzzer clock = 2MHz.  (period of 1k results in 2kHz tone) */
{
  CCR0 = cycles; 
  CCR1 = cycles >> 1;		/* one half cycle */
}


    
    
  

