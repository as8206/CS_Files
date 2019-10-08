//Andrew Stake
//CMPE 320
//Section 2
//ICE_6

#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>

#define LENGTH 25
#define READ_END 0
#define WRITE_END 1

int main(int argc, char **argv)
{
   int onePipe[2];
   if (pipe(onePipe) == -1)
   {
      fprintf(stderr, "Pipe failed");
      return 1;
   }

   pid_t pid = fork();

   if (pid < 0) {
      perror("Error: fork failed.");
      exit(-1);
   }
  
   if (pid == 0) 
   {
      int sequence[LENGTH];
      sequence[0] = 0;
      sequence[1] = 1;
      for (int i = 2; i < LENGTH; i++)
      {
         sequence[i] = sequence[i-1] + sequence[i-2];
      }
      
      write(onePipe[WRITE_END], sequence, sizeof(sequence) + 1);
      close(onePipe[WRITE_END]);
   }
   else
   {
      int status;
      waitpid(pid, &status, 0);
      int readSequence[LENGTH];

      read(onePipe[READ_END], readSequence, sizeof(readSequence) + 1);
      close(onePipe[READ_END]);
      for (int i = 0; i < LENGTH - 1; i++)
         printf("%d, ", readSequence[i]);
     
      printf("%d.\n", readSequence[LENGTH - 1]);
   }

   return 0;
}
