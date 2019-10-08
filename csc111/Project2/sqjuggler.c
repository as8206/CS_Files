/* Project 2: sqjuggler.c
   Programmers: Andrew Stake
   Class: CS2
   Professor: Dr. Lee
   File Created: May 2, 2017
   File Updated: May 3, 2017
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stackADT.h"
#include "queueADT.h"

#define MAX_LEN 10

int main(int argc, char *argv[])
{
   FILE *fp;                                     //declare file pointer and variables
   char line[MAX_LEN];
   char command[MAX_LEN];
   int num;
   Stack inStack, outStack;                      //creates the 2 stacks
   Queue inQueue, outQueue;                      //creates the 2 queues

   inStack = createStack();                      //intializes the stacks and queues
   outStack = createStack();
   inQueue = createQueue();
   outQueue = createQueue();

   if (argc != 2)                                //ensures the correct format was given
   {
      printf("usage: ./lab14 filename\n");
      exit(EXIT_FAILURE);
   }
   
   if ((fp = fopen(argv[1], "r")) == NULL)      //opens the file and checks that it can be opened
   {
      printf("%s can't be opened\n", argv[1]);
      exit(EXIT_FAILURE);
   }
  
   while (fgets(line, sizeof(line), fp))         //goes through the file reading each line into the line variable
   {
      strtok(line, "\n");                        //removes the new line character from the string
      strcpy(command, strtok(line, " "));        //takes the first word from the line and stores it in command
      if (strcmp(command, "add") == 0)           //if command is add, reads in number and pushes it to inStack and inQueue
      {
         num = atoi(strtok(NULL, " "));
         pushStack(inStack, num);
         pushQueue(inQueue, num);
      }
      else if (strcmp(command, "delete") == 0)   //if command is delete, pops from inStack and inQueue and pushes the values into outQueue and outStack respectively
      {
         pushStack(outStack, popQueue(inQueue));
         pushQueue(outQueue, popStack(inStack));
      }
      else
      {
         printf("Invalid command phrase\n");
      }
   }

   printf("outStack: ");                         //prints outStack by using pop and printing the result until outStack is empty
   while(!is_emptyStack(outStack))
   {
      printf("%d ", popStack(outStack));
   }
   printf("\n");

   printf("outQueue: ");                         //prints outQueue by using pop and printing the result until outQueue is empty
   while(!is_emptyQueue(outQueue))
   {
      printf("%d ", popQueue(outQueue));
   }
   printf("\n");
 
   return 0;
}
      
