#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>

void execute(const char *binary, char *const arguments[], char *const envp[])
{
   if (execve(binary, arguments, envp) < 0)
   {
      perror("Could not execute command.");
   }
}

int main(int argc, char **argv, char **envp)
{
   pid_t pid = fork();

   if (pid<0) {
      perror("Error: fork failed.");
      exit(-1);
   }

   if (pid == 0) {
      if (argc == 0)
         argv[1] = "./";
 
      char *arguments[4] = { "/bin/ls", argv[1], "-1", 0x00 };  //Add extra argument after bin/ls to change directory

      execute("/bin/ls", arguments, envp);

      abort();
   }
  
   else
   {
      int status;

      printf("Waiting for command to finish.\n");
      waitpid(pid, &status, 0);
      printf("This is still the parent: child exited with status %x\n", status);
   }

   return 0;
}
