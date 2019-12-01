CC=gcc
AR=ar
OBJECTS_MAIN = main.o
OBJECTS_LIB = myBank.o
FLAGS= -Wall -g

all: myBanklibary mains

myBanklibary:myBanklibary.a

mains: main.o myBanklibary.a
	$(CC) $(FLAGS) -o mains main.o myBanklibary.a

myBanklibary.a: myBank.o
	$(AR) rcs -o myBanklibary.a myBank.o

main.o:myBank.h main.c
	$(CC) $(FLAGS) -c -FPIC main.c

myBank.o:myBank.c
	$(CC) $(FLAGS) -c -FPIC myBank.c

.PHONY: all clean myBanklibary


clean:
	rm -f *.o *.a *.so mains maind