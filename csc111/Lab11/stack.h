/* Lab 11: stack.h
   Programmer: Andrew S and Gabe W
   Class: CS2
   Professor: Dr. Lee
   File Created: March 30, 2017
   File Updated: March 30, 2017
*/

#ifndef STACK_H
#define STACK_H

typedef enum {FALSE, TRUE} bool;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int i);
int pop(void);

#endif 
