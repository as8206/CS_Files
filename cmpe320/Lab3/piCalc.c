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

#define pointsPerThread 1500000
#define totalThreads 20


pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
long pointsInCircle = 0;
void *runner(void *param);
bool available = true;

int main(int argc, char *argv[])
{

   pthread_mutex_init(&mutex,NULL);

   pthread_t tid[totalThreads];
   pthread_attr_t attr[totalThreads];
 
   for(int i = 0; i < totalThreads; i++)
   {
      pthread_attr_init(&attr[i]);
      if(pthread_create(&tid[i], &attr[i], runner, NULL) != 0)
      {
         fprintf(stderr, "Error: Could not create thread %d.\n", i);
         return -1;
      }
   }
   for(int i = 0; i < totalThreads; i++) {
      if(pthread_join(tid[i],NULL) != 0)
      {
         fprintf(stderr, "Error: Could not join thread %d.\n", i);
         return -1;
      }
      //printf("Thread %d joined\n", i);
   }

   float pi = (4.0 * pointsInCircle) /(float) (totalThreads * pointsPerThread);

   printf("Calculated Pi: %lf\n", pi);
}

void *runner(void *param)
{
   double x, y;

   srand((unsigned) time(NULL));
   rand();                                                 //seed and initialize random
   
   for (int i = 0; i < pointsPerThread; i++)
   {
      x = (double) rand() / (double) RAND_MAX;;
      y = (double) rand() / (double) RAND_MAX;;
      if (sqrt((x*x)+(y*y)) < 1)
      {
         pthread_mutex_lock(&mutex);
         pointsInCircle++;
         pthread_mutex_unlock(&mutex);
      }
   }
   //pthread_mutex_lock(&mutex);
   //printf("Thread finished, currents points in circle: %ld\n", pointsInCircle);
   //pthread_mutex_unlock(&mutex);
   pthread_exit(0);
}
