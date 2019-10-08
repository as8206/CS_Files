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

const char* readLine();
char** breakLineArguments(char line[]);

int main()
{
   char* lineIn = readLine();
   printf("Read line: %s\n", lineIn);

   char** arguments = breakLineArguments(lineIn);

   for (int i = 0; i < (wordCount+1); ++i)
      printf ("lineNew[%d] = %s\n", i, arguments[i]);
}

const char* readLine()
{
   int size = 128, index = 0;
   char* lineIn = malloc(size);
   char charIn = getc(stdin);
   boolean charSeen = false;

   while (charIn != EOF && charIn != '\n')            //Reads in the user input on the command line and dynamically allocates space to allow for variable length input
   {
      if (index >= size)
      {
         size = size + 128;
         lineIn = realloc(lineIn, size);
      }
      if (charSeen == true)
      {
         lineIn[index] = charIn;
         index++;
         printf("Added char: %c\n", charIn);
      }
      else if (charSeen == false && charIn != ' ')
      {
         charSeen = true;
         lineIn[index] = charIn;
         index++;
         printf("Added char: %c\n", charIn);
      } 

      charIn = getc(stdin);
   }

   if (index >= size+1)
   {
      size = size + 8;
      lineIn = realloc(lineIn, size);
   }
   lineIn[index] = '\0';

    
   return lineIn;
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
