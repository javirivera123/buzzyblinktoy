#include <msp430.h>
#include "switches.h"
#include "led.h"
#define RESISTOR_ENABLE P2REN
#define INTERRUPT_ENABLE P2IE
#define PULLUP_ENABLE P2OUT
#define SET_INPUT_OUTPUT_BITS P2DIR
#define INTERRUPT_EDGE_TRIGGERED_UP_OR_DOWN P2IES
#define P2_INPUTS P2IN

char switch_state_down, switch_state_changed;


static char switch_update_interrupt_sense(){

    //update switch interrupt sensitivity /
    INTERRUPT_EDGE_TRIGGERED_UP_OR_DOWN |= (P2_INPUTS  & SWITCHES);//if switch up, trigger down
    INTERRUPT_EDGE_TRIGGERED_UP_OR_DOWN &= (P2_INPUTS | ~SWITCHES); //if switch down, trigger up
    return P2_INPUTS;
}

void switch_setup(){

    RESISTOR_ENABLE |= SWITCHES;		// enables resistors for switches
    INTERRUPT_ENABLE = SWITCHES;		// enable interrupts from switches
    PULLUP_ENABLE |= SWITCHES;		// pull-ups for switches
    SET_INPUT_OUTPUT_BITS  &= ~SWITCHES;       // set switches' bits for input

    switch_interrupt_handler();	// to initially read the switches, here is where the light toggles
    //and different beats correspond to diferent buttons


}

void switch_interrupt_handler(){

    char port2_switch_values_pressed = switch_update_interrupt_sense();
    char switches_pressed = (P2IFG & SWITCHES);

    if( switches_pressed == SWITCH1 ){
        switch1_handler();

    }else if(switches_pressed == SWITCH2 ){
        switch2_handler();

    }else if( switches_pressed == SWITCH3 ){
        switch3_handler();

    }else if( switches_pressed == SWITCH4){
        switch4_handler();

    }

}


void switch1_handler(){
    //play beat number one when switch 1 pressed
    buzzer_beat1_default();
    //chage down to one to change  to color red
    switch_state_down = 1;
    //notify led class that there was a change so update could perform proper
    //change
    switch_state_changed = 1;
    led_update();


}

void switch2_handler(){
    //play beat number 2 when switch 2 pressed
    buzzer_beat2();
    switch_state_down = 0;
    switch_state_changed = 1;
    led_update();


}

void switch3_handler(){
    //play beat number 3 when switch 3 pressed
    buzzer_beat3();
}

void switch4_handler(){
//play beat number 4 when switch 4 pressed
    buzzer_beat4();

}
