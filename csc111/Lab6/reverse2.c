/* Lab 6: reverse.c
   Programmer: Andrew Stake
   Class: CS2
   Professor: Dr. Lee
   File Created: Feb 28, 2017
   File Updated: Feb 28, 2017
*/

/* Reverses a series of numbers using a variable-length array - C99 only */

#include<stdio.h>

int main()
{
   int i, n;

   printf("How many numbers do you want to reverse? ");
   scanf("%d", &n);                     //Prompts for and inputs amount of nums
  
   int a[n];                            //Creates the array of n size

   printf("Enter %d numbers: ", n);     //Prompts for numbers to reverse
   for (i = 0; i < n; i++)
      scanf("%d", &a[i]);
   
   printf("In reverse order:");         //Prints the numbers in reverse order
   for ( i = n - 1; i >= 0; i--)
      printf(" %d", a[i]);
   printf("\n");

   return 0;
}
