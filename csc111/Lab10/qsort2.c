/* Lab 10: qsort2.c
   Programmer: Andrew Stake and Shane A
   Class: CS2
   Professor: Dr. Lee
   File Created: March 28, 2017
   File Updated: March 28, 2017
*/

#include<stdio.h>

#define N 10

void quicksort(int *low, int *high);               //function prototypes
int *split(int *low, int *high);

int main(void)
{
   int a[N], i;

   printf("Enter %d numbers to be stored: ", N);   //gets numbers from user
   for (i = 0; i < N; i++)
      scanf("%d", a+i);

   quicksort(a, a+(N-1));                          //calls quicksort function

   printf("In sorted order: ");
   for (i = 0; i < N; i++)                         //reprints sorted numbers
      printf("%d ", *(a + i));
   printf("\n");

   return 0;
}

void quicksort(int *low, int *high)
{
   int *middle;

   if (low >= high) return;                        //breaks if low index passes high indes
   middle = split(low, high);                      //assign split return value to middle
   quicksort(low, middle - 1);                     //recursively calls quicksort on both remaining halves
   quicksort(middle + 1, high);
}

int *split(int *low, int *high)
{
   int part_element = *low;                        //assigns value to the partitioning element

   for(;;)
   {
      while(low < high && part_element <= *high)   //checks if high is greater than the partition, if yes, moves high left, if not, breaks loop
         high--;
      if (low >= high) break;                      //breaks if low is greater or equal to high
      *low = *high;                                //sets low equal to high, filling the "hole" and moves low one to the right
      low++;

      while (low < high && *low <= part_element)   //checks if low is less than the partition, if yes, moves low right, if not breaks loop
         low++;
      if(low >= high) break;                       //breaks if low is greater or equal to high
      *high = *low;                                //sets high equal to low, filling the "hole" and moves high one to the left
      high++;
   }
   
   *high = part_element;                           //fills the final "hole" with the partition element
   return high;                                    //returns the partition element pointer
} 


