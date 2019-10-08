/* Lab 6: reverse.c
   Programmer: Andrew Stake
   Class: CS2
   Professor: Dr. Lee
   File Created: Feb 28, 2017
   File Updated: Feb 28, 2017
*/

/* Reverses a series of numbers (pointer version) */

#include<stdio.h>

#define N 10

int main()
{
   int a[N], *p;

   printf("Enter %d numbers: ", N);   //prompts to enter a set amount of numbers
   for(p = a; p < a + N; p++)
      scanf("%d", p);                 //puts numbers into array using a pointer

   printf("In reverse order:");
   for(p = a + N - 1; p >= a; p--)    //prints out the array in reverse order
      printf(" %d", *p);
   printf("\n");

   return 0;
}
