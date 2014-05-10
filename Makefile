CC = gcc

CFLAGS  = -std=c99 -g -Wall $(shell pkg-config --cflags cunit)

LDFLAGS = $(shell pkg-config --libs cunit)

.PHONY:
default: main

.PHONY:
test: testmergesort

testmergesort: mergesort.h mergesort.o

main: mergesort.h mergesort.o

mergesort.o: mergesort.h

.PHONY:
all: clean default test

.PHONY:
clean:
	rm -f *.o *.*~ main testmergesort
