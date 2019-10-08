/* Project 2: queueADT.c
   Programmer: Andrew Stake
   Class: CS2
   Professor: Dr. Lee
   File Created: May 2, 2017
   File Updated: May 2, 2017
*/

#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"
#include "queueADT.h"

struct node {
   Item data;
   struct node *next;
};

struct stack_type {
   struct node *top;
};

static void terminate(const char *message)
{
   printf("%s\n", message);
   exit(EXIT_FAILURE);
}

Stack createStack(void)
{
   Stack s = malloc(sizeof(struct stack_type));
   if (s == NULL)
      terminate("Error in create: stack could not be created.");
   s->top = NULL;
   return s;
}

void destroyStack(Stack s)
{
   make_emptyStack(s);
   free(s);
}

void make_emptyStack(Stack s)
{
   while (!is_emptyStack(s))
      popStack(s);
}

bool is_emptyStack(Stack s)
{
   return s->top == NULL;
}

bool is_fullStack(Stack s)
{
   return FALSE;
}

void pushStack(Stack s, Item i)
{
   struct node *new_node = malloc(sizeof(struct node));
   if (new_node == NULL)
      terminate("Error in push: stack is full.");
 
   new_node->data = i;
   new_node->next = s->top;
   s->top = new_node;
}

Item popStack(Stack s)
{
   struct node *old_top;
   Item i;

   if (is_emptyStack(s))
      terminate("Error in pop: stack is empty.");

   old_top = s->top;
   i = old_top->data;
   s->top = old_top->next;
   free(old_top);
   return i;
}
