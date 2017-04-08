#include <msp430.h>
#include "buzzer.h"
static unsigned int period = 1000;
static signed int rate = 200;
static unsigned int sound_pressure = 1000;
#define PORT2_CONFIGURE P2SEL2
#define P2_PIN_BEHAVIOR P2SEL
#define P2_INPUT_OUTPUT P2DIR
#define MIN_PERIOD 1000
#define MAX_PERIOD 4000

void buzzer_setup(){

    //Direct timer A output "TA0.1" to P2.6.
    //According to table 21 from data sheet:
    //P2SEL2.6, P2SEL2.7, anmd P2SEL.7 must be zero
    //P2SEL.6 must be 1
    //Also: P2.6 direction must be output

    timerAUpmode();		       //used to drive speaker
    PORT2_CONFIGURE &= ~(BIT6 | BIT7);
    P2_PIN_BEHAVIOR &= ~BIT7;
    P2_PIN_BEHAVIOR |= BIT6;
    P2_INPUT_OUTPUT = BIT6;		//enable output to speaker (P2.6)

}

void buzzer_beat1_default() {
    period += rate;
    char  rate_and_Period_greater = (rate > 0 && (period > MAX_PERIOD));
    char  rate_and_Period_smaller = (rate < 0 && (period < MIN_PERIOD));

    if (rate_and_Period_greater ||  rate_and_Period_smaller) {
        rate = -rate;
        period += (rate << 1);
    }
    buzzer_set_period(period^sound_pressure);//change sound here!!!
}

void buzzer_beat2() {
    period += rate;
    char  rate_and_Period_greater = (rate > 0 && (period > MAX_PERIOD));
    char  rate_and_Period_smaller = (rate < 0 && (period < MIN_PERIOD));

    if (rate_and_Period_greater ||  rate_and_Period_smaller) {
        rate = -rate;
        period += (rate << 1);
    }
    buzzer_set_period(period ^  10000);//change sound here!!!
}

void buzzer_beat3() {
    period += rate;
    char  rate_and_Period_greater = (rate > 0 && (period > MAX_PERIOD));
    char  rate_and_Period_smaller = (rate < 0 && (period < MIN_PERIOD));

    if (rate_and_Period_greater ||  rate_and_Period_smaller) {
        rate = -rate;

        period += (rate << 1);
    }
    buzzer_set_period(period + 2000);//change sound here!!!
}

void buzzer_beat4() {
    period += rate;
    char  rate_and_Period_greater = (rate > 0 && (period > MAX_PERIOD));
    char  rate_and_Period_smaller = (rate < 0 && (period < MIN_PERIOD));

    if (rate_and_Period_greater ||  rate_and_Period_smaller) {
        rate = -rate;

        period += (rate << 1);
    }
    buzzer_set_period(period ^ 2000);//change sound here!!!
}

void buzzer_set_period(short cycles){
    //cycles to play  sound!!

    CCR0 = cycles;
    CCR1 = cycles >> 1;		//one half cycle
}






