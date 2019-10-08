#include<stdlib.h>
#include<stdio.h>
#include<string.h>

static int myCompare (const void * a, const void * b)
{
    return strcmp (*(const char **) a, *(const char **) b);
}
 
void sort(const char *arr[], int n)
{
    qsort (arr, n, sizeof (const char *), myCompare);
}

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
         //printf("env #%d: %s\n", j, var);
      j++;
   } while (var!=NULL);

   sort(envp, j);

   j = 0;
   do
   {
      var = envp[j];
      if(var!=NULL)
         printf("env #%d: %s\n", j, var);
      j++;
   } while (var!=NULL);
}

