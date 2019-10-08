/* Exam 1
   Programmer: Andrew Stake
   Class: CS2
   Professor: Dr. Lee
   File Created: Feb 28, 2017
   File Updated: Feb 28, 2017
*/

#include<stdio.h>

int main()
{
   int n;

   printf("Enter a number: ");   //Prompts for user number entry
   scanf("%d", &n);

   do                            //Reverses the number that is entered
   {
      printf("%d", n % 10);    
      n /= 10;
   }while(n > 0);

   printf("\n");

   return 0;
}
