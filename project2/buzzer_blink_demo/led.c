#include "msp430.h"
#include "led.h"
#include "switches.h"
#define SET_PORT1_INPUT_OUTPUTS P1DIR
#define PORT1_OUTPUTS P1OUT

void led_setup(){

  SET_PORT1_INPUT_OUTPUTS |= LEDS;		//bits attached to leds are output
  switch_state_changed = 1;                     //activate led lighting by indicating change
  led_update();

}

void led_update(){

  //if changed by the button instead of a automatic toggle
  if(switch_state_changed){
    char led_Flags = 0;

    //change leds in led_Flags() accordingly from what is read from
    //button handlers
    led_Flags = set_Led_Flags(led_Flags, switch_state_down);

    PORT1_OUTPUTS &= (0xff^LEDS) | led_Flags;//clear bit for the off leds
    PORT1_OUTPUTS |= led_Flags;//set bits for on leds

  }
  switch_state_changed = 0;


}

char  set_Led_Flags(char led_Flags, char switch_state_down){
  char leds_changed = led_Flags;
  char switch_down_up = switch_state_down;

  //change led to green the first time
  //if state is down the first time
  //then red led will light up otherwise remain
  //in red
  if(switch_down_up){
    leds_changed |=  LED_RED;
  }else{
    leds_changed |= 0;
  }

  //then to red when other button pressed
  //second time the state is down or button2 is pressed
  //the light will light back up to green
  if(switch_down_up){
    leds_changed |=  0;
  }else{
    leds_changed |= LED_GREEN;
  }

  return leds_changed;
}


