/* Lab 11: stackADT.h
   Programmer: Andrew Stake
   Class: CS2
   Professor: Dr. Lee
   File Created: March 30, 2017
   File Updated: March 30, 2017
*/

#ifndef STACKADT_H
#define STACKADT_H

typedef enum {FALSE, TRUE} bool;

typedef int Item;

typedef struct stack_type *Stack;

Stack create(void);
void destroy(Stack s);
void make_empty(Stack s);
bool is_empty(Stack s);
bool is_full(Stack s);
void push(Stack s, int i);
int pop(Stack s);

#endif
