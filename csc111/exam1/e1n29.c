/* Exam 1
   Programmer: Andrew Stake
   Class: CS2
   Professor: Dr. Lee
   File Created: Feb 28, 2017
   File Updated: Feb 28, 2017
*/

#include<stdio.h>

int main(int argc, char *argv[])
{
   char tbt[2][2];                              //creates array for question
   int i, j;                                    //count variables

   for(i = 0; i < 2; i++)
   {
      for(j = 0; j < 2; j++)
      {
         tbt[i][j] = ((i + j) % 2 ? 'A' : 'B'); //if i plus j is even a B is stored there, if odd, an A is stored
         printf("%c", tbt[i][j]);
      }
   }
   printf("\n");

   return 0;
}
