/* Lab 11: stackclient2.c
   Programmer: Andrew Stake
   Class: CS2
   Professor: Dr. Lee
   File Created: March 30, 2017
   File Updated: March 30, 2017
*/

#include <stdio.h>
#include "stackADT2.h"

int main()
{
   Stack s1, s2;
   int n;

   s1 = create(100);
   s2 = create(200);
 
   push(s1, 1);
   push(s1, 2);

   n = pop(s1);
   printf("Popped %d from s1\n", n);
   push(s2, n);
   n = pop(s1);
   printf("Popped %d from s1\n", n);
   push(s2, n);
  
   destroy(s1);

   while (!is_empty(s2))
      printf("Popped %d from s2\n", pop(s2));

   push(s2, 3);
   make_empty(s2);
   if (is_empty(s2))
      printf("s2 is empty\n");
   else
      printf("s2 is not empty\n");

   return 0;
}
