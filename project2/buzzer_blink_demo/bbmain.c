#include <msp430.h>
#include <libTimer.h>
#include "buzzer.h"		/* for setPeriod */
#include "led.h"		/* for led_control() */

void main(void) {

        configureClocks();//disable watchdog timer avoid error

        led_setup();
        switch_setup();
        buzzer_setup();

        or_sr(0x18);  // CPU off, GIE on

    }





