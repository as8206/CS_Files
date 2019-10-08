/* CSC111 Computer Science II
   Lab 3 Conditionals & Loops: lab3b.c
   Programmer: Andrew McCoy and Andrew Stake
   Professor: Dr. Lee
   File Created: Feb 2, 2017
   File Updated: Feb 2, 2017
*/

#include <stdio.h>

int main()
{
   int n; 
   int n2 = 1;
   
   printf("Enter an integer: ");
   scanf("%d", &n);                //Scans in the value n
   printf("%d ", n);
   while(n != 1)                   // Loops till n = 1
   {
      if(n%2 == 0)                 //Checks if n is even or odd
       n = n/2;                    //Math equation
      else                         //Does this if odd
       n = (n*3) + 1;              //Math equation
      printf("%d ", n);
      n2++;                        //Increments n2 for each cycle
   }
   printf("\nCycle length: %d\n", n2);
   return 0;
}
