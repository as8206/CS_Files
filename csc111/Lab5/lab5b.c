/* CSC111 Computer Science II
   Lab 5: Pass by Reference
   Programmers: Shane Allison & Andrew S.
   Professor: Dr. Lee
   File Created: February 16, 2017
   File Updated: February 16, 2017
*/

#include <stdio.h>
#include "lab5.h"				//includes the headers

int main()
{
   int i = 1;					//assigns 1 to i
   int j = 2;					//assigns 2 to j
   printf("i = %d, j = %d\n", i, j);		//prints #s before swap
   swap2(&i, &j);				//theoretically swaps #s
   printf("i = %d, j = %d\n", i, j);		//prints #s AFTER swap
   return 0;
}

void swap2(int *a, int *b)
{
   printf("*a = %d, *b = %d\n", *a, *b);	//prints the value of the pointers pre-swap
   int temp = *a;				//initializes temp and assigns *a to it
   *a = *b;					//assigns *b to *a
   *b = temp;					//assigns temp (*a) to *b
   printf("*a = %d, *b = %d\n", *a, *b);	//prints the value of the pointers post-swap
}
