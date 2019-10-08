/* Project 2: stackADT.h
   Programmer: Andrew Stake
   Class: CS2
   Professor: Dr. Lee
   File Created: April 2, 2017
   File Updated: April 2, 2017
*/

#ifndef QUEUEADT_H
#define QUEUEADT_H

typedef enum {FALSE, TRUE} bool;

typedef int Item;

typedef struct queue_type *Queue;

Queue createQueue(void);
void destroyQueue(Queue q);
void make_emptyQueue(Queue q);
bool is_emptyQueue(Queue q);
bool is_fullQueue(Queue q);
void pushQueue(Queue q, int i);
int popQueue(Queue q);

#endif
