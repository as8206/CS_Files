/* Project 2: stackADT.h
   Programmer: Andrew Stake
   Class: CS2
   Professor: Dr. Lee
   File Created: May 2, 2017
   File Updated: May 2, 2017
*/
#include "queueADT.h"

#ifndef STACKADT_H
#define STACKADT_H

typedef int Item;                                //defines the Item type

typedef struct stack_type *Stack;                //declares the stack type

Stack createStack();                             //function declarations
void destroyStack(Stack s);
void make_emptyStack(Stack s);
bool is_emptyStack(Stack s);
bool is_fullStack(Stack s);
void pushStack(Stack s, int i);
int popStack(Stack s);

#endif
