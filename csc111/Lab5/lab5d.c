/* CSC111 Computer Science II
   Lab 5: Passing by Reference And Value
   Programmers: Shane Allison & Andrew S.
   Professor: Dr. Lee
   File Created: February 16, 2017
   File Updated: February 16, 2017
*/

#include <stdio.h>
#include "lab5.h"

int main()
{
   int i = 1;					//assigns 1 to i
   int j = 2;					//assigns 2 to j
   printf("before: i = %d, j = %d\n", i, j);	//prints values before swap
   swap4(&i, j);				//swaps i and j (but mainly i)
   printf("after: i = %d, j = %d\n", i, j);	//prints values after swap
   return 0;
}

void swap4(int *a, int b)
{
   printf("before: *a = %d, b = %d\n", *a, b);	//prints *a and b before swap
   int temp = *a;				//assigns *a to temp
   *a = b;					//assigns b to *a
   b = temp;					//assigns temp to b
   printf("after: *a = %d, b = %d\n", *a, b);	//prints *a and b after swap
}
