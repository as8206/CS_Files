/* Lab4: lab4.c
   Programmer: Andrew Stake, Christian C. and Spencer H.
   Class: CS2
   Professor: Dr. Lee
   File Created: Feb 14th, 2017
   File Updated: Feb 14th, 2017
*/

#include<stdio.h>
#include"lab4.h"
#define NUM 100                            //declare constants

int main()
{
   int s;                                  //declare variables
   printf("This is Lab 4. \n");            
   printf("Let's add some integers.\n");

   s = lab4a(NUM);                         //passes NUM into lab4a function
   printf("lab4a: sum of 1 to %d = %d\n", NUM, s);  //prints results of function pass

   s = lab4b(NUM);                         //passes NUM into lab4b function
   printf("lab4b: sum of 1 to %d = %d\n", NUM, s);  //prints results of function pass

   return 0;
}
