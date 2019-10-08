/* Exam 1
   Programmer: Andrew Stake
   Class: CS2
   Professor: Dr. Lee
   File Created: Feb 28, 2017
   File Updated: Feb 28, 2017
*/

#include<stdio.h>

int main()
{
   int i = 1, j = 2, *p;                   //declares and intializes variables
   int *q = &j;

   p = q;                                  //switches around variables
   *p = i;
   p = &j;

   printf("%d %d %d %d\n", i, j, *p, *q);

   return 0;
}
