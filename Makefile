COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h -I ${LOCAL_INCLUDE} -I ${LOCAL_CC}
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: project.elf 

#additional rules for files
project.elf: ${COMMON_OBJECTS} sound.o led.o switches.o main.o libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: button.elf
	msp430loader.sh project.elf

clean:
	rm -f *.o *.elf

