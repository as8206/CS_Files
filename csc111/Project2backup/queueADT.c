/* Project 2: stackADT.c
   Programmer: Andrew Stake
   Class: CS2
   Professor: Dr. Lee
   File Created: May 2, 2017
   File Updated: May 2, 2017
*/

#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

struct node {                                    //creates node structure to hold a data item and a pointer to the next node
   Item data;
   struct node *next;
};

struct queue_type {
   struct node *back;
   struct node *front;
};

static void terminate(const char *message)
{
   printf("%s\n", message);
   exit(EXIT_FAILURE);
}

Queue createQueue(void)
{
   Queue q = malloc(sizeof(struct queue_type));
   if (q == NULL)
      terminate("Error in create: queue could not be created.");
   q->back = NULL;
   q->front = NULL;
   return q;
}

void destroyQueue(Queue q)
{
   make_emptyQueue(q);
   free(q);
}

void make_emptyQueue(Queue q)
{
   while (!is_emptyQueue(q))
      popQueue(q);
}

bool is_emptyQueue(Queue q)
{
   return q->front == NULL;
}

bool is_fullQueue(Queue q)
{
   return FALSE;
}

void pushQueue(Queue q, Item i)
{
   struct node *new_node = malloc(sizeof(struct node));
   struct node *last = malloc(sizeof(struct node));

   if (new_node == NULL)
      terminate("Error in push: Queue is full.");
   for(last->next = q->front; last->next != NULL; last = last->next);

   new_node->data = i;
   new_node->next = NULL;
   if(is_emptyQueue(q))
   {
      q->front = new_node;
   }
   q->back = new_node;
   last->next = new_node;
}

Item popQueue(Queue q)
{
   struct node *old_front;
   Item i;

   if (is_emptyQueue(q))
      terminate("Error in pop: queue is empty.");

   old_front = q->front;
   i = old_front->data;
   q->front = old_front->next;
   free(old_front);
   return i;
}
