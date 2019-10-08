#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define WID 2
#define LEN 2
int main()
{
   int a[WID][LEN];
   int i;
   int j;
   int sum;
   for(i = 0; i < WID; i++)
      for(j = 0; j < LEN; j++)
         a[i][j] = 1;
   for(i = 0; i < WID; i++)
      for(j = 0; j < LEN; j++)
         printf("%d ", a[i][j]);
   sum = sum_two_dimensional_array(a, WID);
   printf("%d\n", sum);
}

int sum_two_dimensional_array(const int a[][LEN], int n)
{
   int *p, sum = 0;

   for (p=a[0]; p < a[0] + LEN + n; p++)
      sum += *p;

   return sum;
}
