/* Lab 10: p455n16.c
   Programmer: Andrew S and Shane A
   Class: CS2
   Professor: Dr. Lee
   File Created: March 28, 2017
   File Updated: March 28, 2017
*/

#include<stdio.h>

int sum(int (*f) (int), int, int);
int g(int);                                //prototypes for functions

int main()
{
   int i = 1, j = 0;

   while(i>j)                              //ensures i will be less than j 
   {
      printf("Please enter first value: ");
      scanf(" %d", &i);
      printf("Please enter second (greater) value: ");
      scanf("%d", &j);                     //reads in the value of i and j from the user.
   }
   printf("Answer: %d\n", sum(g, i, j));   //calls sum function and prints result
   
   return 0;
}

int sum(int (*f) (int), int start, int end)
{
   int i, sum = 0;
   for(int i = start; i <= end; i++)       //loops from start value to end value
   {
      sum += (*f)(i);                      //sums all of the calls to the given function
   }
   
   return sum;                             //returns the summation
}

int g(int x)
{
   return (2*x) + 3;                       //performs simple operation on input
}
