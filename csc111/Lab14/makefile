# Lab 14: makefile
# Programmers: Andrew S, Mike S, Spencer H
# Class: CS2
# Professor: Dr. Lee
# File Created: April 20, 2017
# File Updated: April 20, 2017


SOURCES = lab14.c lab14b.c 
OBJECTS = lab14.o lab14b.o
HEADERS = lab14.h
CC = gcc
CFLAGS = -g -Wall

lab14: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o lab14
clean:
	rm -fR *o lab14
	rm -fR temp.dat result
