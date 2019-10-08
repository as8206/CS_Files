/*
 * Andrew Stake
 * CMPE 320 Section 2
 * Lab 3
 * S. Lee
 */

#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<sys/types.h>

typedef int bool;
#define true 1
#define false 0

#define points 1500000

long pointsInCircle = 0;
void *runner(void *param);
bool available = true;

int main(int argc, char *argv[])
{

   pthread_t tid;
   pthread_attr_t attr;
 
   pthread_attr_init(&attr);
   if(pthread_create(&tid, &attr, runner, NULL) != 0)
   {
      fprintf(stderr, "Error: Could not create thread.\n");
      return -1;
   }
   if(pthread_join(tid,NULL) != 0)
   {
      fprintf(stderr, "Error: Could not join thread.\n");
      return -1;
   }

   float pi = (4.0 * pointsInCircle) /(float) (points);

   printf("Calculated Pi: %lf\n", pi);
}

void *runner(void *param)
{
   double x, y;

   srand((unsigned) time(NULL));
   rand();                                                 //seed and initialize random
   
   for (int i = 0; i < points; i++)
   {
      x = (double) rand() / (double) RAND_MAX;;
      y = (double) rand() / (double) RAND_MAX;;
      if (sqrt((x*x)+(y*y)) < 1)
      {
         pointsInCircle++;
      }
   }
   //printf("Thread finished, currents points in circle: %ld\n", pointsInCircle);
   pthread_exit(0);
}
