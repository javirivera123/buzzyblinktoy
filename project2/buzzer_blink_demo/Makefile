# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h 
LDFLAGS = ../lib/libTimer.a

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: button.elf buttonS.elf

#additional rules for files
button.elf: ${COMMON_OBJECTS} ports_interrupt_handler.o  led.o switches.o buzzer.o bbmain.o ../lib/libTimer.a
	${CC} ${CFLAGS} $^ $(LDFLAGS) -o $@

buttonS.elf: ${COMMON_OBJECTS} ports_interrupt_handler.o  led.o switches.o buzzer.o bbmain.o ../lib/libTimer.a
	${CC} ${CFLAGS} $^ $(LDFLAGS) -o $@

load: button.elf
	mspdebug rf2500 "prog $^"

loadS: buttonS.elf
	mspdebug rf2500 "prog $^"

clean:
	rm -f *.o *.elf


bbmain.o: led.h switches.h buzzer.h
led.o: led.h switches.h led.s led.c
switches.c: switches.h
buzzer.c: buzzer.h

