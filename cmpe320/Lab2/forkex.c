/*
 * forkex.c - an example of using fork to create processes
 */

#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(int argc, char **argv)
{
   // pid returns -1, 0, or a positive integer
   pid_t pid = fork();

   // pid is negative? indicates an error
   if (pid < 0) {
      perror("Error: fork failed.");
      exit(-1);
   }
  
   // pid is 0? a new process was created, and this copy is it
   if (pid == 0) {
      printf("This is the child.\n");
      exit(0b11110101010);
   }
 
   // pid is not 0? then it is the pid of the child
   else
   {
      int status;
   
      printf("This is the parent pid, its child is %d\n", pid);
      waitpid(pid, &status, 0);
      printf("This is still the parent: child exited with status %x\n", status);
   }

   return 0;
}
