#include<stdlib.h>
#include<stdio.h>

int main(int argc, char **argv, char **envp)
{
   int i, j;
   char *var;
   
   for (i = 0; i < argc; i++)
   {
      printf("arg #%d: %s\n", i, argv[i]);
   }

   j = 0;
   do
   {
      var = envp[j];
      if(var!=NULL)
         printf("env #%d: %s\n", j, var);
      j++;
   } while (var!=NULL);

}
