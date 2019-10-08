/* Lab2: p69n9b.c
   Programmer: Andrew Stake
   Class: CS2
   Professor: Dr. Jeonghwa Lee
   File Created: January 31, 2017
   File Updated: January 31, 2017
*/

#include<stdio.h>

int main()
{
   int i, j, k;
   i = j = k = 1;
   i += j += k;
   
   printf("%d %d %d\n", i, j, k);
  
   return 0;
}
