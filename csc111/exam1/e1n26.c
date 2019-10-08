/* Exam 1
   Programmer: Andrew Stake
   Class: CS2
   Professor: Dr. Lee
   File Created: Feb 28, 2017
   File Updated: Feb 28, 2017
*/

#include<stdio.h>

int mystery(int);

int main()                            //main function to test mystery function
{
   int result;                        //variable to hold return from mystery

   result = mystery(4);               //Call to the mystery function with number from question
   printf("Result: %d\n", result);    //prints result

   return 0;
}

int mystery(int n)                    //Mystery function from question
{
   if (n <= 1)
      return 1;
   else
      return n * mystery(n - 1);
}
