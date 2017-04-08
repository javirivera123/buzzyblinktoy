#include <msp430.h>
#include "switches.h"

// Switch on Port2 if needed to change to port 1 do so accordingly 
__interrupt(PORT2_VECTOR) Port_2(){
    if (P2IFG & 0x0f) {                   // did a button cause this interrupt? 
        switch_interrupt_handler();
        P2IFG &= ~0x0f;	               // clear pending sw interrupts 

    }

}

