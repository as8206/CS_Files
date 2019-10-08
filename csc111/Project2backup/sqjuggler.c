/* Project 2: sqjuggler.c
   Programmers: Andrew S, Mike S, Spencer H
   Class: CS2
   Professor: Dr. Lee
   File Created: May 2, 2017
   File Updated: May 2, 2017
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stackADT.h"
#include "queueADT.h"

#define MAX_LEN 10

int main(int argc, char *argv[])
{
   FILE *fp;
   char line[MAX_LEN];
   char command[MAX_LEN];
   int num;
   Stack inStack, outStack;
   Queue inQueue, outQueue;

   inStack = createStack();
   outStack = createStack();
   inQueue = createQueue();
   outQueue = createQueue();

   if (argc != 2)
   {
      printf("usage: ./lab14 filename\n");
      exit(EXIT_FAILURE);
   }
   
   if ((fp = fopen(argv[1], "rb")) == NULL)
   {
      printf("%s can't be opened\n", argv[1]);
      exit(EXIT_FAILURE);
   }
  
   while (fgets(line, sizeof(line), fp))
   {
      strtok(line, "\n");
      printf("line: %s\n", line);
      strcpy(command, strtok(line, " "));
      printf("command: %s\n", command);
      if (strcmp(command, "add") == 0)
      {
         num = atoi(strtok(NULL, " "));
         pushStack(inStack, num);
         pushQueue(inQueue, num);
      }
      else if (strcmp(command, "delete") == 0)
      {
         pushStack(outStack, popQueue(inQueue));
         pushQueue(outQueue, popStack(inStack));
      }
      else
      {
         printf("Invalid command phrase\n");
      }
   }

   printf("outStack: ");
   while(!is_emptyStack(outStack))
   {
      printf("%d ", popStack(outStack));
   }
   printf("\n");

   printf("outQueue: ");
   while(!is_emptyQueue(outQueue))
   {
      printf("%d ", popQueue(outQueue));
   }
   printf("\n");
 
   return 0;
}
      
