OBJECTS = CelestialBody.o Universe.o main.o
CC = g++ -g
CFLAGS = --std=c++14 -Wall -Werror -pedantic
LIB = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lboost_unit_test_framework

all: $(OBJECTS) NBody lint


CelestialBody.o: CelestialBody.hpp CelestialBody.cpp 
	$(CC) $(CFLAGS) -c CelestialBody.cpp -o CelestialBody.o

Universe.o: Universe.hpp Universe.cpp 
	$(CC) $(CFLAGS) -c Universe.cpp -o Universe.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o main.o

NBody: main.o
	$(CC) $(CFLAGS) -o PS3a $(OBJECTS) -o NBody $(LIB)

lint:
	cpplint --filter=-runtime/references,-build/include_subdir,-build/header_guard,-build/c++11 *.cpp *.hpp

clean:
	rm *.o NBody