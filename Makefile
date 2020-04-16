COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I./h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as
AR              = msp430-elf-ar

all: project.elf 

#additional rules for files
project.elf: ${COMMON_OBJECTS} sound.o led.o switches.o main.o libTimer.a AssembleMachines.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: project.elf
	msp430loader.sh project.elf

clean: clean-timer
	rm -f *.o *.elf

timer: libTimer.a

libTimer.a: clocksTimer.o sr.o
	$(AR) crs $@ $^

install-timer: libTimer.a
	mkdir -p ./h ./lib
	mv $^ ./lib
	cp *.h ./h

clean-timer:
	rm -f timerLib.a
	rm -r ./h ./lib

