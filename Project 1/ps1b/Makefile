OBJECTS = FibLFSR.o PhotoMagic.o
CC = g++
CFLAGS = --std=c++14 -Wall -Werror -pedantic
LIB = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lboost_unit_test_framework

all: $(OBJECTS) PhotoMagic



FibLFSR.o: FibLFSR.hpp FibLFSR.cpp 
	$(CC) $(CFLAGS) -c FibLFSR.cpp -o FibLFSR.o

PhotoMagic.o: PhotoMagic.cpp
	$(CC) $(CFLAGS) -c PhotoMagic.cpp -o PhotoMagic.o

PhotoMagic: FibLFSR.o
	$(CC) $(CFLAGS) -o PS1 $(OBJECTS) -o PhotoMagic $(LIB)

clean:
	rm *.o PhotoMagic