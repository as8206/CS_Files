/* Exam 1
   Programmer: Andrew Stake
   Class: CS2
   Professor: Dr. Lee
   File Created: Feb 28, 2017
   File Updated: Feb 28, 2017
*/

#include<stdio.h>

int main()                          //main to test both parts of question
{
   int sum = 0, i;                  //Beginning of first part
   for (i = 0; i < 10; i++)
   {
      if (!(i%2))                   //Sums even numbers
         sum += i;
   }
   printf("First sum: %d\n", sum);

   sum = 0;                         //Beginning of second part
   for (i = 0; i < 10; i++)
   {
      if (i % 2)                    //Again sums even numbers
         continue;
      sum += i;
   }
   printf("Second sum: %d\n", sum);
}
