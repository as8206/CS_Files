/*
 * Andrew Stake
 * CMPE 320 Section 2
 * Lab 4
 * S. Lee
 */

#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/types.h>
#include<semaphore.h>
#include<unistd.h>

typedef int bool;
#define true 1
#define false 0

void *runner(void *param);
void *timerRunner(void *param);
void *schedulerRunner(void *param);
bool available = true;

int *burst_time;
int thread_count;
int cur_thread_count;
int turn = -1;
int timeQuantum;
int runTime = false;
bool shift = true;

sem_t timer;
sem_t ready;

int main(int argc, char *argv[])
{
   sem_init(&ready, 0, 0);
   sem_init(&timer, 0, 1);  // maybe 0,0

   //check for valid arguments
   if(argc != 3)
   {
      fprintf(stderr, "Error: Format should be ./<executable> <amount of threads> <time quantum>\n");
      return -1;
   }
   else if(atoi(argv[1]) < 1 || atoi(argv[1]) > 10)
   {
      fprintf(stderr, "Error: Number of threads must be between 1 and 10\n");
      return -1;
   }
   else if(atoi(argv[2]) <= 0)
   {
      fprintf(stderr, "Error: Time Quantum must be a positive, non-zero integer\n");
      return -1;
   }

   //assign arguments to variables   
   int numOfUserThreads = atoi(argv[1]);
   timeQuantum = atoi(argv[2]);

   burst_time = malloc(sizeof(int) * numOfUserThreads);
   thread_count = numOfUserThreads;
   cur_thread_count = thread_count;

   //get burst times for the threads
   for(int i = 0; i < numOfUserThreads; i++)
   {
      printf("Burst Time for Thread %d: ", i);
      scanf("%d", &burst_time[i]);
   }

   printf("-----------------------------------------------\n");

   //Creation of the threads
   pthread_t tid[numOfUserThreads], tidTimer, tidScheduler;
   pthread_attr_t attr[numOfUserThreads], attrTimer, attrScheduler;
   
   for(int i = 0; i < numOfUserThreads; i++)
   {
      pthread_attr_init(&attr[i]);
      if(pthread_create(&tid[i], &attr[i], runner, (void *)i) != 0)
      {
         fprintf(stderr, "Error: Could not create thread %d.\n", i);
         return -1;
      }
   }
   
   pthread_attr_init(&attrTimer);
   if(pthread_create(&tidTimer, &attrTimer, timerRunner, (void *)timeQuantum) != 0)
   {
      fprintf(stderr, "Error: Could not create timer thread.\n");
      return -1;
   }

   pthread_attr_init(&attrScheduler);
   if(pthread_create(&tidScheduler, &attrScheduler, schedulerRunner, NULL) != 0)
   {
      fprintf(stderr, "Error: Could not create timer thread.\n");
      return -1;
   }

   //Joining of the threads
   if(pthread_join(tidScheduler,NULL) != 0)
   {
      fprintf(stderr, "Error: Could not join scheduler thread.\n");
      return -1;
   }

   if(pthread_join(tidTimer, NULL) != 0)
   {
      fprintf(stderr, "Error: Could not join timer thread.\n");
      return -1;
   }

   for(int i = 0; i < numOfUserThreads; i++) {
      if(pthread_join(tid[i],NULL) != 0)
      {
         fprintf(stderr, "Error: Could not join thread %d.\n", i);
         return -1;
      }
   }
}

void *runner(void *param)
{
   int tid = (int) param;

   while(burst_time[tid] > 0)
   {
      if(turn == tid && shift)
      {
         sem_wait(&ready);
         printf("\tThread %d is now being executed.\n", tid);
         if(burst_time[tid] > timeQuantum)
         {
            runTime = timeQuantum;
            burst_time[tid] = burst_time[tid] - timeQuantum;
         }
         else
         {
            runTime = burst_time[tid];
            burst_time[tid] = 0;
         }
         shift = false;
      }
   }

   cur_thread_count--;
}

void *timerRunner(void *param)
{
   int timeCount = 1;
   while(cur_thread_count > 0)
   {
      if(shift == false)
      {
         for(int i = 0; i < runTime; i++)
         {
            sleep(1);
         
            printf("%d\n", timeCount);
            timeCount++;
         }
         finish:
         sem_post(&timer);
      }
   }
}

void *schedulerRunner(void *param)
{
   int modifier;

   sem_wait(&timer);
   while(cur_thread_count > 0)
   {
      rerun_scheduling_logic:
      modifier = 1;

      thread_already_finished:

      if (turn+modifier <= thread_count)
      {
         if (burst_time[turn+modifier] == 0)
         {
            modifier++;
            goto thread_already_finished;
         }
         else
            turn = turn + modifier;
      }
      else
      {
         turn = -1;
         goto rerun_scheduling_logic;
      }

      sem_post(&ready);
      shift = true;

      sem_wait(&timer);
      if(burst_time[turn] <= 0 && turn != -1)
            printf("\tThread %d finishes its job. It will be terminated.\n", turn);
   }
   printf("\tAll threads have done their work. The scheduler thread exits.\n");
}







