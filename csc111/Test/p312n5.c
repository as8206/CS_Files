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
   int sum2 = 0;
   int i, j;
   char *p = &argv[1][0];

   for(i = 0; i < argc; i++)
   {
      sum2 = 0;
      for(j = 0; *p != '\0'; p++)
      {
         sum2 = sum2 * (10 * j) + ((int) *p - 48);
         j++;
      }
      sum = sum + sum2;
      p++;
   }
    printf("Sum of command-line arguments: %d\n", sum);

   return 0;
}
