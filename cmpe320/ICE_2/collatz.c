#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
   pid_t pid;
   int input = -1;
   
   while(input < 1)
   {
      printf("Please enter a positive integer:\n");
      scanf("%d", &input); 
   } 
   pid = fork();

   if (pid < 0)
   {
      fprintf(stderr, "Fork Failed\n");
      return 1;
   }
   else if (pid==0)
   {
      while(input != 1)
      {
         printf("%d, ", input);
  
         if ((input%2) == 0)
         {
            input = input / 2;
         }
         else if ((input%2) == 1)
         {
            input = (input * 3) + 1;
         }
         
      }
      printf("1\n");
   }
   else
   {
      wait(NULL);
      printf("Child Complete");
   }
  
   return 0;
}
