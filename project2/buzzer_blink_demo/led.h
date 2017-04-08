#ifndef led_included
#define  led_included

#include "msp430g2553.h"

#define LED_RED BIT0               // P1.0
#define LED_GREEN BIT6             // P1.6
#define LEDS (BIT0 | BIT6)

void led_setup();		// initialize LEDs
void led_update();              // update leds
void led_toggle();
char  set_Led_Flags(char Leds_to_set, char state_down);
void automatic_toggle();

// these are boolean flags
extern unsigned char red_on, green_on;


#endif
