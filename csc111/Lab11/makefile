HEADERS = stack.h stackADT.h stackADT2.h
CC = gcc
CFLAGS = -g -Wall

stack1: stack1.o driver.o
	$(CC) $(CFLAGS) stack1.o driver.o -o run
stack2: stack2.o driver.o
	$(CC) $(CFLAGS) stack2.o driver.o -o run
stackADT: stackADT.o stackclient.o
	$(CC) $(CFLAGS) stackADT.o stackclient.o -o run
stackADT2: stackADT2.o stackclient2.o
	$(CC) $(CFLAGS) stackADT2.o stackclient2.o -o run
stackADT3: stackADT3.o stackclient.o
	$(CC) $(CFLAGS) stackADT3.o stackclient.o -o run

clean:
	rm -fR *o run
