/* Lab2: p70n10a.c
   Programmer: Andrew Stake
   Class: CS2
   Professor: Dr. Jeonghwa Lee
   File Created: January 31, 2017
   File Updated: January 31, 2017
*/

#include<stdio.h>

int main()
{
   int i = 6, j;
   j = i += i;
   
   printf("%d %d\n", i, j);
  
   return 0;
}
