//Lab2: MIPS
//Andrew Stake
//Program that takes 2 inputs from the user, and adds all of
//the even numbers between those inputs

#include <stdio.h>
#include <stdlib.h>

int main()
{
   int x, y, xEven, yEven, sum = 0;

   printf("Please enter values for X and Y\n");  //Prompts the user for data entry
   scanf("%d", &x);
   scanf("%d", &y);                              //reads in the data
   
   if(x%2 == 1 || x%2 == -1)                     //checks that x is even, if odd adds one to make it even while keeping it within the range
      x = x + 1;
   if(y%2 == 1 || x%2 == -1)                     //checks that y is even, if odd subtracts one to make it even while keeping it within the range
      y = y - 1;
   
   while (x <= y)                                //runs while x is less than or equal to y
   {
      sum = sum + x;                             //adds x to the current sum
      x += 2;                                    //increments x by 2 to go to the next even number
   }
   
   printf("The sum of the even integers between X and Y is: %d\n", sum);

   return 0;
}
