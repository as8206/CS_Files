/* Project 2: stackADT.c
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

struct node {                                    //creates node structure to hold a data item and a pointer to the next node
   Item data;
   struct node *next;
};

struct stack_type {                              //defines the stack type ADT
   struct node *top;
};

static void terminate(const char *message)       //sets up the function to terminate the instance if an error occurs
{
   printf("%s\n", message);
   exit(EXIT_FAILURE);
}

Stack createStack(void)                          //initializes the stack
{
   Stack s = malloc(sizeof(struct stack_type));  //creates a space in memory to hold the stack
   if (s == NULL)                                //checks to insure the space is allocated correctly
      terminate("Error in create: stack could not be created.");
   s->top = NULL;                                //sets both pointer to NULL
   return s;
}

void destroyStack(Stack s)                       //empties the stack and then frees the space
{
   make_emptyStack(s);
   free(s);
}

void make_emptyStack(Stack s)                    //empties the stack by using pop until the stack is empty
{
   while (!is_emptyStack(s))
      popStack(s);
}

bool is_emptyStack(Stack s)                      //checks if the stack is empty by seeing if the top pointer is NULL, thus empty
{
   return s->top == NULL;
}

bool is_fullStack(Stack s)                       //returns false, as the stack could only be full if computer is out of memory
{
   return FALSE;
}

void pushStack(Stack s, Item i)                  //adds an item to the queue
{
   struct node *new_node = malloc(sizeof(struct node));
   if (new_node == NULL)
      terminate("Error in push: stack is full.");
 
   new_node->data = i;                           //fills the new node with data and sets its next pointer to NULL as it is on the top of the stack
   new_node->next = s->top;
   s->top = new_node;                            //sets the top pointer to the new node
}

Item popStack(Stack s)                           //removes the node at the top of the stack and returns its value
{
   struct node *old_top;                         //creates a node to hold the old top node
   Item i;

   if (is_emptyStack(s))
      terminate("Error in pop: stack is empty.");

   old_top = s->top;                             //sets the old top node equal to the current top node
   i = old_top->data;
   s->top = old_top->next;                       //sets the top pointer to the node below the top most one
   free(old_top);                                //removes the top node
   return i;
}
