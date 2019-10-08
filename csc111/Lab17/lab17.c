#include <stdio.h>
#include <stdlib.h>

int checkIfTrue(int i, int j, int p, int q)
void printCase(int i, int j, int p, int q, int non[]);

int main(void)
{
   int inside[4];
   int outside[8];
   int nonprime[8] = {1, 4, 6, 8, 9, 10, 12};
   int prime[4] = {2, 3, 5, 7, 11};
   int i, j, p, q;
   
   for (i = 0; i < 5; i++)
   {
      for (j = 0; j < 5; j++)
      {
         for (p = 0; p < 5; p++)
         {
            for (q = 0; q < 8; q++)
            {
               if (checkIfTrue(prime[i],prime[j], prime[p], nonprime[q]))
               {
                  printCase(prime[i], prime[j], prime[p], nonprime[q], nonprime);
               }
            }
         }
      }
   }  
    
   return 0;
}

int checkIfTrue(int i, int j, int p, int q)
{
   if ((i + j + p + q) == 26)
   {
      return true;  
   }
}


void printCase(int i, int j, int p, int q, int non[])
{
   printf("Inner: %d %d %d %d\n", i, j, p, q);
   return;
}
