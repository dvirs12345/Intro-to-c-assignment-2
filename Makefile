CC=gcc
AR=ar
OBJECTS_MAIN = main.o
OBJECTS_LIB = myBank.o
FLAGS= -Wall -g

# Creates all the nessecery files 
all: myBanklib mains

# Runs myBanklib.a segment
myBanklib:myBanklib.a

# Creates mains
mains: main.o myBanklib.a
	$(CC) $(FLAGS) -o mains main.o myBanklib.a

# Creates myBank.o
myBanklib.a: myBank.o
	$(AR) rcs -o myBanklib.a myBank.o

# Links myBank.h and main.c
main.o:myBank.h main.c
	$(CC) $(FLAGS) -c -FPIC main.c

# Compile myBank.c
myBank.o:myBank.c
	$(CC) $(FLAGS) -c -FPIC myBank.c

.PHONY: all clean myBanklib

# Removes all .o,a,so and mains files
clean:
	rm -f *.o *.a *.so mains