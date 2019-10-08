//Andrew Stake
//CMPE 220
//Project 2

#include<stdio.h>
#include<stdlib.h>

int main()
{
   int sequence[20];
   int index, sum, hiSum, hiSumLength;
   int i, j, k, temp;
   char check;

   printf("Please enter your sequence, up to 20 integers: \n");
   
   i = 0;
   hiSum = 0;
   while(i < 20)
   {
      scanf("%d%c", &temp, &check);    //stores an integer as well as the next character to use as a check
      sequence[i] = temp;              //stores the int into the array
      hiSum = hiSum + temp;            //adds the int to the largest sum variable
      if(check == '\n')                //checks if it is the end of the input
         break;
      i++;
   }
   hiSumLength = i;
   
   k = i;
   while(k >= 0)                       //loops, reducing length until 0
   {
   
      j = 0;
      sum = 0;
      while(j <= k)                    //runs through length of the sequence finding the sum
      {
         sum = sum + sequence[j];
         j++;

      }
      
      if(sum > hiSum)                  //checks if the instance sum is greater than the current largest sum
      {
         hiSum = sum;
         hiSumLength = k;
      }
     
      k--;
   }
   
   printf("\nArray: ");                //prints all of the results
   j = 0;
   while (j <= i)
   {
      printf("%d ", sequence[j]);
      j++;
   }
   
   printf("\nSubsequence: ");
   j = 0;
   while (j <= hiSumLength)
   {
      printf("%d ", sequence[j]);
      j++;
   }
   
   printf("\nLargest Sum: %d\n\n", hiSum);
}
