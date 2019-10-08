# Lab 15: makefile
# Programmer: Andrew S, Mike S, Spencer H
# Class: CS2
# Professor: Dr. Lee
# File Created: April 20, 2017
# File Updated: April 20, 2017

all: canopen fcopy

clean:
	rm -f canopen fcopy 
	rm -fR *o canopen fcopy

canopen: canopen.c
	gcc -o canopen canopen.c
fcopy: fcopy.c
	gcc -o fcopy fcopy.c
