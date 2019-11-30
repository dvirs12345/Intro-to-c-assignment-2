CC=gcc
AR=ar
OBJECTS_MAIN=main.o
OBJECTS_LIB=myBank.o 
FLAGS= -Wall -g

# Creates all the necessary files.
all: libmyBank.so libmyBank.a mains maind	

# Creates a static library containing the file objects
mains: myBanks $(OBJECTS_MAIN) 
	$(CC) $(FLAGS) -o mains $(OBJECTS_MAIN) libmyBank.a 

# Creates a shared library containing the file objects
maind: myBankd $(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o maind $(OBJECTS_MAIN) ./libmyBank.so

# Creates a file that links main and the static library
myBankd: $(OBJECTS_LIB)
	$(CC) -shared -o libmyBank.so $(OBJECTS_LIB)

# Creates a file that links main and the shared library
myBanks: $(OBJECTS_LIB)
	$(AR) -rcs libmyBank.a $(OBJECTS_LIB)	

# Links myBank.c and myBank.h
myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -fPIC -c myBank.c

# Links Main and .h
main.o: main.c myBank.h  
	$(CC) $(FLAGS) -c main.c 

# Removes all .o .a and .so files and mains and maind
clean:
	rm -f *.o *.a *.so mains maind
