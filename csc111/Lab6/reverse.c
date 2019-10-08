/* Lab 6: reverse.c
   Programmer: Andrew Stake
   Class: CS2
   Professor: Dr. Lee
   File Created: Feb 28, 2017
   File Updated: Feb 28, 2017
*/

/* Reverses a series of numbers */

#include<stdio.h>

#define N 10                           //creates constant N equal to 10

int main()
{
   int a[N], i;

   printf("Enter %d numbers: ", N);   //prompts to enter a set amount of numbers
   for(i = 0; i < N; i++)
      scanf("%d", &a[i]);             //puts numbers into array

   printf("In reverse order:");
   for(i = N - 1; i >= 0; i--)        //prints out the array in reverse order
      printf(" %d", a[i]);
   printf("\n");

   return 0;
}
