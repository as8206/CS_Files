# Project 2: makefile
# Programmer: Andrew Stake
# Course: CS2
# Professor: Dr. Lee
# File Created: May 2, 2017
# File Updated: May 2, 2017

SOURCES = sqjuggler.c stackADT.c queueADT.c
OBJECTS = sqjuggler.o stackADT.o queueADT.o
HEADERS = stackADT.h queueADT.h
CC = gcc
CFLAGS = -g -Wall

sqjuggler: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o sqjuggler
clean:
	rm -fR *o sqjuggler
