/* Lab 4: ch10s35.c
   Programmer: Andrew Stake
   Class: CS2
   Professor: Dr. Lee
   File Created: Feb 14, 2017
   File Updated: Feb 14, 2017
*/

#include<stdio.h>

int i;

void f(int);
void g(void);
void h(void);

int main()
{   
   f(1);
   g();
   h();

   return 0;
}

void f(int i)
{
   i = 1;

   printf("Function f value: %d\n", i);
}

void g(void)
{
   int i = 2;

   if (i > 0)
   {
      int i;
      i = 3;

      printf("Fuction g, if statement value: %d\n", i);
   }

   i = 4;

   printf("Fucntion g value: %d\n", i);
}

void h(void)
{
   i = 5;
   
   printf("Function h value: %d\n", i);
}
