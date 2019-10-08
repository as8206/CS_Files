/* CSC111 Computer Science 2
   Lab 10: Quicksort
   Programmers: Shane A. & Andrew S.
   Professor: Dr. Lee
   File Created: March 28, 2017
   File Updated: March 28, 2017
*/

#include <stdio.h>

#define N 10

void quicksort(int a[], int low, int high);		//quicksort prototype
int split(int a[], int low, int high);			//split prototype

int main()
{
   int a[N], i;
   
   printf("Enter %d numbers to be sorted: ", N);
   for (i = 0; i < N; i++)
      scanf("%d", &a[i]);                               //gets numbers from the user
   quicksort(a, 0, N-1);                                //Calls quicksort function
 
   printf("In sorted order: ");
   for(i = 0; i < N; i++)                               //reprints sorted numbers
      printf("%d ", a[i]);
   printf("\n");

   return 0;
}

void quicksort(int a[], int low, int high)
{
   int middle;

   if (low >= high) return;				//break if low index passes high index
   middle = split(a, low, high);			//assign split return value to middle
   quicksort(a, low, middle - 1);			//recursively run quicksort
   quicksort(a, middle + 1, high);			//recursively run quicksort
}

int split(int a[], int low, int high)
{
   int part_element = a[low];				//assigns first value to partition element

   for (;;) {
      while (low < high && part_element <= a[high])
         high--;					//move high index down as high value is greater than partition
      if (low >= high) break;				//break if low index passes high index
      a[low++] = a[high];				//assign high value to low position and increment low
      
      while (low < high && a[low] <= part_element)
         low++;						//move low index up as low value is less than partition
      if (low >= high) break;				//break if low index passes high index
      a[high--] = a[low];				//puts the low value in high position and decrements
   }

   a[high] = part_element;				//assigns the partition to high position
   return high;						//returns high index
}
