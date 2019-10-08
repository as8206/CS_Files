#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

int average, min, max;
int numOfNums;
int* nums;

void *runnerAverage(void* param);
void *runnerMin(void* param);
void *runnerMax(void* param);

int main(int argc, char *argv[])
{
   pthread_t tid1, tid2, tid3;
   pthread_attr_t attr1, attr2, attr3;
   
   if (argc < 2)
   {
      fprintf(stderr, "usage: a.out <integer values>\n");
      return -1;
   }
   numOfNums = argc - 1;
   int tempNums[numOfNums];

   for(int i = 0; i < numOfNums; i++)
   {
      tempNums[i] = atoi(argv[i+1]);
   }
   nums = tempNums;
 
   pthread_attr_init(&attr1);
   pthread_attr_init(&attr2);
   pthread_attr_init(&attr3);
   pthread_create(&tid1, &attr1, runnerAverage, argv);
   pthread_create(&tid2, &attr2, runnerMin, argv);
   pthread_create(&tid3, &attr3, runnerMax, nums);
   pthread_join(tid1,NULL);
   pthread_join(tid2,NULL);
   pthread_join(tid3,NULL);

   printf("The average value is %d\n", average);
   printf("The minimum value is %d\n", min);
   printf("The maximum value is %d\n", max);
}

void *runnerAverage(void*  param)
{
   int i;
   int sum = 0; 

   for (i = 0; i < numOfNums; i++)
      sum += nums[i];
   average = sum / numOfNums;
   pthread_exit(0);
}

void *runnerMin(void* param)
{
   int low = nums[0], i;

   for (i = 0; i < numOfNums; i++)
   {
      if (nums[i] < low)
         low = nums[i];
   }
   min = low;
   pthread_exit(0);
}

void *runnerMax(void* param)
{
   int *nums2 = param;
   int high = nums2[0], i;
   
   for (i = 0; i < numOfNums; i++)
   {
      if (nums2[i] > high)
         high = nums2[i];
   }
   max = high;
   pthread_exit(0);
}
