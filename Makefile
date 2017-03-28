CC=g++
CXXFLAGS=-std=c++11 -Wall -g

# Not working with minGW, but works when sshing, decided to automakefile for now

all: test

test: Fridge.o Item.o

Fridge.o: Fridge.h Item.h
	$(CC) $(CXXFLAGS) -c -o Fridge.o Fridge.cpp
Item.o: Item.h
	$(CC) $(CXXFLAGS) -c -o Item.o Item.cpp
clean:
	rm -f test *.o core*