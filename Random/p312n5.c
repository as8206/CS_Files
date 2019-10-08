/* Lab 6: p312n5.c
   Programmer: Andrew Stake
   Class: CS2
   Professor: Dr. Lee
   File Created: Feb 28, 2017

*/

#include<stdio.h>

int main(int argc, char *argv[])
{
   int sum = 0;
   int i;

   for(i = 0; i < argc; i++)
   {
      sum = sum + argv[i]
   }
   printf("Sum of command-line arguments: %d\n", sum);

   return 0;
}
