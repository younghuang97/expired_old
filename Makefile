CC=g++
CXXFLAGS=-std=c++11

all: test

test: Fridge.o Item.o

Fridge.o: Fridge.h Item.h

Item.o: Item.h

clean:
	rm -f test *.o core*