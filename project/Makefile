# makefile configuration

COMMON_OBJECTS  =

CPU             = msp430g2553

CFLAGS          = -mmcu=${CPU} -I..demos/h

LDFLAGS 	= -L/opt/ti/msp430_gcc/include



#switch the compiler (for the internal make rules)

CC              = msp430-elf-gcc

AS              = msp430-elf-as



all: project.elf
#additional rules for files

project.elf: ${COMMON_OBJECTS} main.o switches.o led.o buzzer.o interruptHandler.o stateMachine.o lib/libTimer.a

	${CC} $(CFLAGS) $(LDFLAGS) -o $@ $^



load: project.elf

	msp430loader.sh project.elf



clean:

	rm -f *.o *.elf

	rm -rf lib h

main.o: led.h switches.h buzzer.h

led.o: led.h

interruptHandler.o: stateMachine.h buzzer.h

switches.o: led.h switches.h stateMachine.h buzzer.h
