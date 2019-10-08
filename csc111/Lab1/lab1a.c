/* CSC11 Computer Science II
   Lab 1 Getting to know Linus: lab1a.c
   Programmer: Andrew Stake
   Professor: Dr. Lee
   File Created: Jan 26, 2017
   File Updated: Jan 26, 2017
*/

#include<stdio.h>

#define N 100

int main()
{
   int i;
   i = 5;                //You can also declear and assign value as int i = 5
   printf("Yes, this is your fantastic playground!!!\n");
   printf("What is N? %d\n", N);     //print out the constant N on the screen
   printf("What is i? %d\n", i);     //print out the value of integer i on the screen
   printf("What is N * i? %d\n", N * i);   //print out the value of N*i on the screen
   return 0;
}
