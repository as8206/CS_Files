SOURCES = xor.c viewmemory.c
OBJECTS = xor.o viewmemory.o
CC = gcc
CFLAGS = -g -Wall

xor: $(OBJECTS)
	$(CC) $(CFLAGS) xor.o -o xor
viewmemory: $(OBJECTS)
	$(CC) $(CFLAGS) viewmemory.o -o viewmemory
clean:
	rm -fR *o xor newmsg viewmemory
