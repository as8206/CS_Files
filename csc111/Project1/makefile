
SOURCES = testdna.c countBase.c
OBJECTS = testdna.o countBase.o
HEADERS = testdna.h
CC = gcc
CFLAGS = -g -Wall

testdna: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o testdna
clean:
	rm -fR *o testdna
