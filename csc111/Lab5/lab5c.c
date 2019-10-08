/* CSC111 Computer Science II
   Lab 5: Pass by value and Pass by referenc: lab5c.c
   Programmer: Andrew Stake and Shane A.
   Professor: Dr. Lee
   File Created: Feb 16th, 2017
   File Updated: Feb 16th, 2017
*/

#include<stdio.h>
#include"lab5.h"

int main()
{
   int i = 1;                                //declares variables to be swapped
   int j = 2;
   printf("before: i = %d, j = %d\n", i, j); //prints values before swap
   swap3(i, &j);                              //calls the swap function
   printf("after: i = %d, j = %d\n", i, j);  //prints values after swap
   
   return 0;
}

void swap3(int a, int *b)                     //function to swap two values
{
   printf("before: a = %d, b = %d\n", a, *b);//prints a and b values before swap
   int temp = a;                             //creates temp variable to hold a
   a = *b;                                   //stores value of b into a
   *b = temp;                                //stores value of temp into b
   printf("after: a = %d, b = %d\n", a, *b); //prints a and b values after swap
}
   
