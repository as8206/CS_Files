/* Lab 11: driver.c
   Programmer: Andrew S and Gabe W
   Class: CS2
   Professor: Dr. Lee
   File created: March 30, 2017
   File updated: March 30, 2017
*/

#include <stdio.h>
#include "stack.h"

int main()
{
   int i,  n;
   int a[] = {1, 2, 3, 4, 5};               //array is 5 as that is the max stack value in stack.c

   for(i = 0; i < 5; i++)                   //fills the stack from the array
      push(a[i]);
  
   if(is_full())                            //ensures the stack was full and the is_full() function is working correctly
      printf("Stack is full\n");
   else
      printf("Stack is not full\n");
 
   for(i = 0; i < 5; i++)                   //removes values from the stack, and prints out the removed value
   {
      n = pop();
      printf("Popped %d from stack\n", n);
   }

   if(is_empty())                           //ensures the stack is now empty and that the is_empty() function is working correctly
      printf("Stack is empty\n");
   else
      printf("Stack is not empty\n");

   return 0;
} 
