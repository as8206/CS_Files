/*
*Lab 4: : 
*Programmer: Luke Kuehler Christopher Roadcap
*Course: CMPE 320
*Section 2
*Instructor: S. Lee
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <math.h>
#include <semaphore.h>
#include <unistd.h>

int timeQua = 5; //intialized to values to debug but changed in user input anyways
int threadNum = 5; //intialized to values to debug but changed in user input anyways
int threadsrunning; //keeps tracking of threads that are still waiting/active
int run = 1; //keeps the timer running, exits when told by scheduler
int currenttime = 0;
int timeBurst = 0;
int earlyexit = 0; //did the thread exit before full time quantum

int turn = 0;
int check = 1;

//setting up the semaphores
sem_t timer; //sema for timer
sem_t ready; //sema for starting threads
sem_t waittimer; //keeps runner at the same time as timer

int bursts[10] = {5,8,8,5,5,5,5,5,5,5}; //intialized to values to debug but changed in user input anyways

void *runner(void *param);
void *scheduler(void *param);
void *timerfunc(void *param);

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int main(int argc, char *argv[])
{
	//commandline for number of threads and time quantum
	threadNum = atoi(argv[1]);
	timeQua = atoi(argv[2]);

	int start = 0;
	//reads user input to set burst time for each thread
	for(int i = 0; i < threadNum; i++)
	{
		printf("Enter burst time for thread %d: ", i);
		fflush(stdout);
		scanf("%d", &bursts[i]);
		printf("\n");
		fflush(stdout);
		start = 1;
	}
	//threadsrunning will start at the number of threads initialized
	threadsrunning = threadNum;
	//initialize semaphores
	sem_init(&ready, 0, 0);
	sem_init(&timer, 0, 1);
	
	//setting up pthreads
	pthread_t tid[threadNum], tidSched, tidTimer;
	pthread_attr_t attr, attr2, attr3;
	
	//policies and such
	pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);
	int policy = SCHED_RR;
	pthread_attr_setschedpolicy(&attr, policy);

	pthread_attr_init(&attr);
	pthread_attr_init(&attr2);
	pthread_attr_init(&attr3);

	int id[threadNum];
	//initialize each thread
	for (int i = 0; i < threadNum; i++)
	{
		id[i] = i;
		pthread_create(&tid[i],&attr,runner,(void*)(id + i)); //change null to burst index
		printf("initialized thread %d \n", id[i]);
		fflush(stdout);
		usleep(0.0015 * 1000000);
	}
	//create and join both scheduler and timer thread 
	pthread_create(&tidSched,&attr2,scheduler,NULL);
	pthread_create(&tidTimer,&attr3,timerfunc,NULL);
	pthread_join(tidSched, NULL);
	pthread_join(tidTimer, NULL);
	//program finished
	printf("<****Done****>\n");
}

void *runner(void *param)
{
	//wait for scheduler to begin running
	sem_wait(&ready); 
	int* num = (int*)param; //use *num as thread number
	printf("Executing thread: %d \n", *num);
	fflush(stdout);
	//initialize current burst tracker and the burstconstant
	int trackBurst = 0;
	int burstConstant = 0;
	while(bursts[*num] != trackBurst)
	{	
           if(turn == num && check)
           {
		//if burst constant has reached time constant, reset to 0, and add back to waiting queue
		if(burstConstant == timeQua)
		{
			burstConstant = 0;
			sem_wait(&ready);
			printf("Executing thread: %d \n", *num);
			fflush(stdout);
		}
		else //else continue running the current thread
		{
			sem_wait(&waittimer);
			burstConstant++;
			trackBurst++;
		}
                check = 0;
           }
	}
	//usleep(0.00015 * 1000000);
	printf("Thread %d has exited\n", *num);
	fflush(stdout);
	//if the thread finished before the alotted burst time let timer know and adjust
	if(bursts[*num]%timeQua != 0)
	{
			earlyexit = 1;
	}
	pthread_mutex_lock(&mutex);
		//timeBurst = 0;
		threadsrunning--;
	pthread_mutex_unlock(&mutex);
	pthread_exit(0);
}

void *scheduler(void *param)
{
	//creating running while threads are in waiting queue
        int mod = 1;
	while(threadsrunning > 0)
	{
		sem_wait(&timer); //wait for timer
                mod = 1;
                rerun:
                if (turn+mod != threadNum)
                {
                   if(bursts[turn+mod] != 0)
                      turn++;
                   else
                   {
                      mod++;
                      goto rerun;
                   }
                }
                else
                {
                   turn = 0;
                   goto rerun;
                }
                check = 1;
        	sem_post(&ready); //start new thread
		usleep(0.00015 * 1000000);
	}
	run = 0;
	printf("Exit Scheduler\n");
	fflush(stdout);
	pthread_exit(0);
}

void *timerfunc(void *param)
{
	while(run)
	{
		//timer sleep
		sleep(1);
		//if a thread exited before running through full time quantum
		//reset current time burst and post to scheduler
		if(earlyexit)
		{
			earlyexit = 0;
			sem_post(&timer);
			timeBurst = 0;
			continue;
		}

		currenttime++;
		timeBurst++;
		//post to runner, keeps runner synced with this
		sem_post(&waittimer);
		printf("%d\n", currenttime);
		fflush(stdout);
		//once reaching time quantum, post to scheduler
		if(timeBurst == timeQua) {
			sem_post(&timer);
			timeBurst = 0;
		}
	}
	pthread_exit(0);
}
