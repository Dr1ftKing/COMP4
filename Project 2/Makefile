OBJECTS = Triangle.o TFractal.o
CC = g++ -g
CFLAGS = --std=c++14 -Wall -Werror -pedantic
LIB = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lboost_unit_test_framework

all: $(OBJECTS) TFractal lint



Triangle.o: Triangle.hpp Triangle.cpp 
	$(CC) $(CFLAGS) -c Triangle.cpp -o Triangle.o

TFractal.o: TFractal.cpp
	$(CC) $(CFLAGS) -c TFractal.cpp -o TFractal.o

TFractal: Triangle.o
	$(CC) $(CFLAGS) -o PS2 $(OBJECTS) -o TFractal $(LIB)

lint:
	cpplint --filter=-runtime/references,-build/include_subdir,-build/header_guard,-build/c++11 *.cpp *.hpp

clean:
	rm *.o TFractal