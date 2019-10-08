/* Project 2: queueADT.h
   Programmer: Andrew Stake
   Class: CS2
   Professor: Dr. Lee
   File Created: April 2, 2017
   File Updated: April 2, 2017
*/

#ifndef QUEUEADT_H
#define QUEUEADT_H

typedef enum {FALSE, TRUE} bool;                 //creates the boolean type bool

typedef int Item;                                //defines the Item type

typedef struct queue_type *Queue;                //declares the queue type 

Queue createQueue(void);                         //function declarations
void destroyQueue(Queue q);
void make_emptyQueue(Queue q);
bool is_emptyQueue(Queue q);
bool is_fullQueue(Queue q);
void pushQueue(Queue q, int i);
int popQueue(Queue q);

#endif
