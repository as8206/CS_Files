/*
 * Andrew Stake
 * CMPE 320 Section 2
 * Project 2
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

bool failsDeadline();
int checkDeadline();
void updateThreadDeadline(int thread);
int findNextThread();
void resetValues();
void *runner(void *param);
void *timerRunner(void *param);
void *schedulerRunner(void *param);

int *execution_time;
int *period_time;
int *thread_deadline;
int program_time;
int numOfUserThreads;
int curTime;
int execTime;
int turn = -1;
bool schTurn = true;
bool shift = true;
bool idle = false;

sem_t timer;
sem_t ready;
sem_t update;

int main(int argc, char *argv[])
{
   sem_init(&ready, 0, 0);
   sem_init(&timer, 0, 0);
   sem_init(&update, 0, 0);

   //check for valid arguments
   if(argc != 2)
   {
      fprintf(stderr, "Error: Format should be ./<executable> <amount of threads>\n");
      return -1;
   }
   else if(atoi(argv[1]) < 1 || atoi(argv[1]) > 10)
   {
      fprintf(stderr, "Error: Number of threads must be between 1 and 10\n");
      return -1;
   }

   numOfUserThreads = atoi(argv[1]);
   execution_time = malloc(sizeof(int) * numOfUserThreads);
   period_time = malloc(sizeof(int) * numOfUserThreads);
   thread_deadline = malloc(sizeof(int) * numOfUserThreads);

   //get execution times for the threads
   for(int i = 0; i < numOfUserThreads; i++)
   {
      printf("Execution Time for Thread %d: ", i);
      scanf("%d", &execution_time[i]);
   }

   //get period for the threads
   for(int i = 0; i < numOfUserThreads; i++)
   {
      printf("Period for Thread %d: ", i);
      scanf("%d", &period_time[i]);
   }

   //set up initial deadlines
   for(int i = 0; i < numOfUserThreads; i++)
   {
      thread_deadline[i] = period_time[i];
   }

   printf("How long do you want to execute this program (sec): ");
   scanf("%d", &program_time);

   if(failsDeadline())
   {
      printf("These threads can't be scheduled. Program will exit.\n");
      return 0;
   }
   
   resetValues();

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
   if(pthread_create(&tidTimer, &attrTimer, timerRunner, NULL) != 0)
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
   
   return 0;
}

//simulations methods (no sleep or threads)
bool failsDeadline()
{
   curTime = 1;
   turn = checkDeadline();
   execTime = execution_time[turn];

   while(curTime < program_time)
   {
      if(idle)
      {
         //go to scheduler
         turn = findNextThread();
         if (turn!=-1)
         {
            idle = false;
            execTime = curTime + execution_time[turn];
         }
      }
      //this is where the timer would signal the scheduler
      if (curTime == execTime)
      {
         //This is not needed is scheduler, it is only for this simulation
         if (curTime > thread_deadline[turn])
            return true;
         //This is what the scheduler would do (check in method)
         updateThreadDeadline(turn);
         turn = findNextThread();
         if (turn!=-1)
         {
            idle = false;
            execTime = curTime + execution_time[turn];
         }
         else
            idle = true;
         //execTime would then be used as a flag for timer, and the scheduler would return control to timer
      }
      curTime++;
   }
   return false;
}

//this is basically the scheduler thread
int checkDeadline()
{
   int result = 0;
 
   int testValue = thread_deadline[0];
   for(int i = 0; i < numOfUserThreads; i++)
   {
      if (thread_deadline[i] < testValue)
      {
         testValue = thread_deadline[i];
         result = i;
      }
   }

   return result;
}

//this is some of what would happen inside of the user threads
void updateThreadDeadline(int thread)
{
   thread_deadline[thread] = thread_deadline[thread] + period_time[thread];
}

int findNextThread()
{
   int result = -1;
   for(int i = 0; i < numOfUserThreads && result == -1; i++)
   {
      if (curTime >= thread_deadline[i] - period_time[i])
         result = i;
   }
   
   if (result == -1)
      return result;
   
   int testValue = thread_deadline[result];
   for(int i = result; i < numOfUserThreads; i++)
   {
      if (thread_deadline[i] < testValue && curTime >= thread_deadline[i] - period_time[i])
      {
         testValue = thread_deadline[i];
         result = i;
      }
   }
   return result;
}

void resetValues()
{
   //resets time to 0
   curTime = 0;
   //resets the thread deadlines
   for (int i = 0; i < numOfUserThreads; i++)
   {
      thread_deadline[i] = period_time[i];
   }
   //resets turn to neutral value
   turn = -1;
   //resets idle
   idle = false;
}

//Actual scheduler (with sleeps and threads)
void *runner(void *param)
{
   int tid = (int) param;

   while(curTime < program_time)
   {
      if(turn == tid && shift)
      {
         sem_wait(&ready);  //initialize so it can be entered immediately
         printf("Thread %d is now being executed.\n", tid);
         thread_deadline[tid] = thread_deadline[tid] + period_time[tid];
         shift = false;
      }
   }
}

void *timerRunner(void *paraem)
{
   curTime = 1;

   sem_wait(&update);

   while (curTime < program_time)
   {
      if(idle)
      {
         sem_post(&timer);
         sem_wait(&update);
      }
      printf("%d\n", curTime);
      if (curTime == execTime)
      {
         sem_post(&timer);
         sem_wait(&update);
         if(idle)
            printf("CPU is idling now.\n");
      }
      sleep(1);
      curTime++;
   }
   sem_post(&timer);
   printf("Killed\n");
}

void *schedulerRunner(void *param)
{
   turn = checkDeadline();
   execTime = execution_time[turn];

   sem_post(&ready);
   while(shift){}
   sem_post(&update);

   sem_wait(&timer);
   while (curTime < program_time)
   {
      turn = findNextThread();
      if (turn!=-1)
      {
         idle = false;
         execTime = curTime + execution_time[turn];
         sem_post(&ready);
         shift = true;
         while(shift){}
      }
      else
         idle = true;
      sem_post(&update);
      sem_wait(&timer);
   }
   sem_post(&ready);
   sem_post(&update);
}
      
      
      































