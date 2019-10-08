/* Lab 6: p312n5.c
   Programmer: Andrew Stake
   Class: CS2
   Professor: Dr. Lee
   File Created: Feb 28, 2017
   File Updated: Feb 28, 2017
*/

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
   int sum = 0;                        //Variable to hold sum 
   int i;                              //count variable

   for(i = 1; i < argc; i++)           //loop that starts after call to program and continues through any command-line arguments
   {
      sum = sum + atoi(argv[i]);       //sums up the remaining arguments
   }
    printf("Sum of command-line arguments: %d\n", sum);

   return 0;
}
