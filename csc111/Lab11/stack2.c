/* CSC111 Computer Science II
   lab11: stack2.c
   Programmers: Andrew S. and Gabriel W.
   Professor: Dr. Lee
   Date created: March 29, 2017
   Date Updated: March 29, 2017
*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct node {
   int data;
   struct node *next;
}; static struct node *top = NULL;

static void terminate(const char *message)
{
   printf("%s\n", message);
   exit(EXIT_FAILURE);
}

void make_empty()
{
   while (!is_empty())
      pop();
}

bool is_empty()
{
   return top == NULL;
}

bool is_full()
{
   return FALSE;
}

void push(int i)
{
   struct node *new_node = malloc(sizeof(struct node));
   
   if (new_node == NULL)
      terminate("Error in push: stack is full.");

   new_node->data = i;
   new_node->next = top;
   top = new_node;
}

int pop()
{
   struct node *old_top;
   int i;

   if (is_empty())
      terminate("Error in pop: stack is empty");

   old_top = top;
   i = top->data;
   top = top->next;
   free(old_top);
   return i;
}






