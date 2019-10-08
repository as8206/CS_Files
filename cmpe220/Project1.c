//Author: Andrew Stake
//Project 1
//Counting 1's in Binary

#include<stdio.h>

int main()
{
   int input;
   int binary[32];
   int count = 0;
   int i = 0;
   int inputStatic;

   printf("Please enter positive integer: ");
   scanf("%d", &input);

   inputStatic = input;

   while (input > 0)
   {
      binary[i] = input % 2;
      input = input / 2;
      i++;
   }

   while (i >= 0)
   {
      if(binary[i] == 1)
         count++;
      i--;
   }
   
   printf("The number of 1's in %d is: %d\n", inputStatic, count);
   
}
