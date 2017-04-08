#include <msp430.h>
#include "buzzer.h"
#include "led.h"


__interrupt(WDT_VECTOR) WDT(){	//250 interrupts/sec

  static char second_count = 0, decisecond_count = 0;

  if (++second_count == 250) {
    // buzzer_beat4();//testing puroposes
    second_count = 0;
  }
  if (++decisecond_count == 25) {
    // buzzer_beat2(); //testing porposes inital only song of the toy
    decisecond_count = 0;
  }

}
