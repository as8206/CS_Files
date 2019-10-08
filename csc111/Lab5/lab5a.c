/* CSC111 Computer Science II
   Lab 5: Pass by value and Pass by referenc: lab5a.c
   Programmer: Andrew Stake and Shane A.
   Professor: Dr. Lee
   File Created: Feb 16th, 2017
   File Updated: Feb 16th, 2017
*/

#include<stdio.h>
#include"lab5.h"

int main()
{
   int i = 1;                         //declaration of variables to be swapped
   int j = 2;
   printf("i = %d, j = %d\n", i, j);  //Print out values before swap call
   swap1(i, j);                        //calls fuction to swap values
   printf("i = %d, j = %d\n", i, j);  //Print out values after swap call

   return 0;

}

void swap1 (int a, int b)
{
   printf("a = %d, b = %d\n", a, b); //Print out values of parameter before swap
   int temp = a;                     //Creates temporary integer value to hold a
   a = b;                            //places value of b into a
   b = temp;                         //places value in temp back into b
   printf("a = %d, b = %d\n", a, b); //Print out values of parameters after swap
}
