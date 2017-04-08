#ifndef switches_included
#define switches_included

#define SWITCH1 BIT0
#define SWITCH2 BIT1
#define SWITCH3 BIT2
#define SWITCH4 BIT3 //switches 1-4 on green launchpad
#define SWITCHES (SWITCH1 | SWITCH2 | SWITCH3 | SWITCH4 )

void switch_init();
void switch_interrupt_handler();
void switch1_handler();
void switch2_handler();
void switch3_handler();
void switch4_handler();

extern char switch_state_down, switch_state_changed; // effectively boolean

#endif // included
