#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<string.h>

typedef int boolean;
#define true 1
#define false 0

char** lineNew = NULL;
int wordCount = 0;
//char line[] = "Hello World arg1 two argument3";

char** breakLineArguments(char line[]);

int main()
{
   char line[] = "Hello World arg1 two argument3";

   char** words = breakLineArguments(line);

   for (int i = 0; i < (wordCount+1); ++i)
      printf ("lineNew[%d] = %s\n", i, lineNew[i]);
}

char** breakLineArguments(char line[])
{
   char* temp = strtok(line, " ");

   while (temp) 
   {
      wordCount++;
      lineNew = realloc (lineNew, sizeof (char*) * wordCount);

      if (lineNew == NULL)
         exit (-1); /* memory allocation failed */

      lineNew[wordCount-1] = temp;

      temp = strtok (NULL, " "); 
   }

   lineNew = realloc (lineNew, sizeof (char*) * (wordCount+1));
   lineNew[wordCount] = '\0';

   for (int i = 0; i < (wordCount+1); ++i)
      printf ("lineNew[%d] = %s\n", i, lineNew[i]);

   return lineNew;
}
