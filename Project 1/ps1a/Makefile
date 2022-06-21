OBJECTS = FibLFSR.o test.o
CC = g++
CFLAGS = --std=c++14 -Wall -Werror -pedantic
LIB = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lboost_unit_test_framework

all: $(OBJECTS) FibLFSR-app

FibLFSR.o: FibLFSR.hpp FibLFSR.cpp 
	$(CC) $(CFLAGS) -c FibLFSR.cpp -o FibLFSR.o

test.o: test.cpp
	$(CC) $(CFLAGS) -c test.cpp -o test.o

FibLFSR-app: FibLFSR.o
	$(CC) $(CFLAGS) -o PS1 $(OBJECTS) -o FibLFSR-app $(LIB)

clean:
	rm *.o FibLFSR-app
