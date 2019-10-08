/* Project 2: queueADT.c
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

struct queue_type {                              //defines the queue type ADT
   struct node *back;
   struct node *front;
};

static void terminate(const char *message)       //sets up the function to terminate the instance if an error occurs
{
   printf("%s\n", message);
   exit(EXIT_FAILURE);
}

Queue createQueue(void)                          //initializes the queue
{
   Queue q = malloc(sizeof(struct queue_type));  //creates a space in memory to hold the queue
   if (q == NULL)                                //checks to insure the space is allocated correctly
      terminate("Error in create: queue could not be created.");
   q->back = NULL;                               //sets both pointers to NULL
   q->front = NULL;
   return q;
}

void destroyQueue(Queue q)                       //empties the queue and then frees the space
{
   make_emptyQueue(q);
   free(q);
}

void make_emptyQueue(Queue q)                    //empties the queue by using pop until the queue is empty
{
   while (!is_emptyQueue(q))
      popQueue(q);
}

bool is_emptyQueue(Queue q)                      //checks if the queue is empty by seeing if the front pointer is NULL, thus empty
{
   return q->front == NULL;
}

bool is_fullQueue(Queue q)                       //returns false, as the queue could only be full if computer is out of memory
{
   return FALSE;
}

void pushQueue(Queue q, Item i)                  //adds an item to the queue
{
   struct node *new_node = malloc(sizeof(struct node));
   struct node *last = malloc(sizeof(struct node));

   if (new_node == NULL)
      terminate("Error in push: Queue is full.");
   for(last->next = q->front; last->next != NULL; last = last->next); 

   new_node->data = i;                           //fills the new node with data and sets its next pointer to NULL as it is at the back
   new_node->next = NULL;
   if(is_emptyQueue(q))                          //if the queue was previously empty, sets the new node as the front as well
   {
      q->front = new_node;
   }
   q->back = new_node;                           //sets the back pointer to point to the new node
   last->next = new_node;                        //makes the pointer in the last node to point to the new last node  
}

Item popQueue(Queue q)                           //removes the node in the front of the queue and returns its value
{
   struct node *old_front;                       //creates a node to hold the data from the node to be removed
   Item i;

   if (is_emptyQueue(q))
      terminate("Error in pop: queue is empty.");

   old_front = q->front;                         //sets the old node equal to the node at the front of the queue
   i = old_front->data;
   q->front = old_front->next;                   //sets the front pointer to point to the node behind the one that was at the front
   free(old_front);                              //removes the old front node
   return i;
}
