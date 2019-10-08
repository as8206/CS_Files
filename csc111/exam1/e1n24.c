/* Exam #1
   Programmer: Andrew Stake
   Class: CS2
   Professor: Dr. Lee
   File Created: Feb 28, 2017
   File Updated: Feb 28, 2017
*/

#include<stdio.h>

int main()                            //Main file to run exam question test
{
   int i = -1, j = 1, k = 1;          //Declare variables from question
   
   printf("%d ", ++i || ++j && ++ k); //logic from questions
   printf("%d %d %d \n", i, j, k);

   return 0;
}
