//Andrew Stake
//CMPE 320
//Section 2
//ICE 6

#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

long *sequence;
void *runner(void *param);

int main(int argc, char *argv[])
{
   pthread_t tid;
   pthread_attr_t attr;
   
   if (argc != 2)
   {
      fprintf(stderr, "usage: a.out <integer value>\n");
      return -1;
   }
   if (atoi(argv[1]) <= 0)
   {
      fprintf(stderr, "Argument must be greater than 0\n");
      return -1;
   }
   
   sequence = (long*)  malloc((atoi(argv[1])) * sizeof(long));

   pthread_attr_init(&attr);
   pthread_create(&tid, &attr, runner, argv[1]);
   pthread_join(tid,NULL);
   
   for (int i = 0; i < (atoi(argv[1]) - 1); i++)
      printf("%ld, ", sequence[i]);
   printf("%ld.\n", sequence[(atoi(argv[1]) -1)]);
}

void *runner(void *param)
{
   int length = atoi(param);
   
   if (length == 1)
      sequence[0] = 0;
   else if (length == 2)
   {
      sequence[0] = 0;
      sequence[1] = 1;
   }
   else
   {
      sequence[0] = 0;
      sequence[1] = 1;
      for (int i = 2; i < length; i++)
         sequence[i] = sequence[i-1] + sequence[i-2];
   }

   pthread_exit(0);
}
