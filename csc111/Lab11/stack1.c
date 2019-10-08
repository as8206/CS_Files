/* CSC111 Computer Science II
   lab11: stack1.c
   Programmers: Gabriel W and Andrew S.\
   Professor: Dr. Lee
   Date Created: march 29, 2017
   Date Updated: march 29, 2017
*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define STACK_SIZE 5

static int contents[STACK_SIZE];
static int top = 0;

static void terminate(const char *message)            //terminates the program
{
   printf("%s\n", message);
   exit(EXIT_FAILURE);
}

void make_empty()                        
{
   top = 0;
}

bool is_empty()
{
   return top == 0;
}

bool is_full()
{
   return top == STACK_SIZE;
}

void push(int i)
{
   if (is_full())
      terminate("Error in push: stack is full.");
   contents[top++] = i;
}

int pop()
{
   if (is_empty())
     terminate("Error in pop: stack is empty.");
   return contents[--top];
}
