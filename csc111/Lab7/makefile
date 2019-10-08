#makefile

SOURCES = runner.c charlist.c
OBJECTS = runner.o charlist.o
HEADERS = charlist.h
CC = gcc
CFLAGS = -g -Wall

charplay: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o charplay
clean:
	rm -fR *o charplay
