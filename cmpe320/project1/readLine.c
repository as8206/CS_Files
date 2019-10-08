#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<string.h>

typedef int boolean;
#define true 1
#define false 0

const char* readLine();

int main()
{
   char* string;
   string = readLine();
   printf("%s\n", string);
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
