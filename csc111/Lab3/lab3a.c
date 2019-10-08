/* CSC111 Computer Science II
   Lab 3 Conditions & Loops: lab3a.c
   Programmer: Andrew Stake & Andrew McCoy
   Professor: Dr. Lee
   File Created: Feb 2, 2017
   File Updated: Feb 2, 2017
*/

#include <stdio.h>

int main()
{
   int n;
   printf("Enter an integer to find sum: "); //asks user for integer       
   scanf("%d", &n);                          //reads integer from user
   while(n<=0 || n > 4195583)
   {
      printf("Invalid input, try again: ");
      scanf("%d", &n);
   }
   int i; 
   int sum1=0, sum2=0;
   for(i = 1; i <= n; i++)                  //loop from i(starting at 1) to n
   {
      sum1 = sum1 + i;                      //adds sum to itself and i
   }   
   
   sum2 = n * (n+1)/2;                      // uses formula to find sum

   printf("Sum from loop: %d\n", sum1);
   printf("Sum from formula: %d\n", sum2);

   return 0;
}
