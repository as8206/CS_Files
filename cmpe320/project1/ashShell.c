/*
 * Andrew Stake
 * CMPE 320 Section 2
 * Project 1
 * S. Lee
 */

#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<string.h>

typedef int boolean;
#define true 1
#define false 0
#define READ_END 0
#define WRITE_END 1
#define HISTORY 10 //number of lines the history command will display
#define PREV -1 //marker for simply using the previous command, used only in calls to runFromHistory

char** lineNew = NULL;
int wordCount = 0;
char** lineHistory = NULL;
int linesInHistory = 0;

const char* readLine();
char** breakLineArguments(char line[]);
void standardCommand(char** arguments);
void addToHistory(char line[]);
void runFromHistory(int marker);
void execute(const char *binary, char *const arguments[]);

int main()
{
   boolean should_run = true;
   boolean shouldAdd = false;
   pid_t pid;
   int status;
   int onePipe[2];
   int twoPipe[2];

   while(should_run)
   {
      if (pipe(onePipe) == -1)
      {
         fprintf(stderr, "Pipe failed");
         return 1;
      }
      if (pipe(twoPipe) == -1)
      {
         fprintf(stderr, "Pipe failed");
         return 1;
      }

      free(lineNew);
      lineNew = NULL;
      wordCount = 0;

      printf("ash> ");
      char* lineIn = readLine();
      char* lineInHeld = malloc(strlen(lineIn));
      strcpy(lineInHeld, lineIn);
      char** arguments = breakLineArguments(lineIn);
      pid = fork();
  
      if(pid < 0)
      {
         fprintf(stderr, "Error: Fork failed.");
      }
      else if(pid == 0)
      {
         close(onePipe[READ_END]);
         boolean exitStatus = true;
         boolean addToHistory = false;

         if(strcmp("exit", arguments[0]) == 0)
         {
            exitStatus = false;
            write(onePipe[WRITE_END], &exitStatus, sizeof(exitStatus));
            close(onePipe[WRITE_END]);
            write(twoPipe[WRITE_END], &addToHistory, sizeof(addToHistory));
            close(twoPipe[WRITE_END]);
         }
         else if(strcmp("history", arguments[0]) == 0)
         {
            write(onePipe[WRITE_END], &exitStatus, sizeof(exitStatus));
            close(onePipe[WRITE_END]);
            write(twoPipe[WRITE_END], &addToHistory, sizeof(addToHistory));
            close(twoPipe[WRITE_END]);
            
            if(linesInHistory > HISTORY)
            {
               for(int i = linesInHistory - HISTORY; i < linesInHistory; i++)
               {
                  printf("%d: %s\n", linesInHistory-i+linesInHistory-HISTORY, lineHistory[i]);
               } 
            }
            else
            {
               for(int i = 0; i < linesInHistory; i++)
               {
                  printf("%d: %s\n", linesInHistory-i, lineHistory[i]);
               } 
            }
         }
         else if(strcmp("!!", arguments[0]) == 0)
         {
            write(onePipe[WRITE_END], &exitStatus, sizeof(exitStatus));
            close(onePipe[WRITE_END]);
            write(twoPipe[WRITE_END], &addToHistory, sizeof(addToHistory));
            close(twoPipe[WRITE_END]);

            if (linesInHistory > HISTORY)
            {
               runFromHistory(1+linesInHistory-HISTORY);
            }
            else
            {
               runFromHistory(1);
            }
         }
         else if(arguments[0][0] == '!')
         {
            write(onePipe[WRITE_END], &exitStatus, sizeof(exitStatus));
            close(onePipe[WRITE_END]);
            write(twoPipe[WRITE_END], &addToHistory, sizeof(addToHistory));
            close(twoPipe[WRITE_END]);

            char* temp = arguments[0] + 1;
            int marker = atoi(temp);
            if(marker != 0)
               runFromHistory(marker);
            else
               printf("Error: format is !<# in History>\n");
         }
         else
         {
            addToHistory = true;
            write(onePipe[WRITE_END], &exitStatus, sizeof(exitStatus));
            close(onePipe[WRITE_END]);
            write(twoPipe[WRITE_END], &addToHistory, sizeof(addToHistory));
            close(twoPipe[WRITE_END]);

            if(strcmp("&", arguments[wordCount-1]) == 0)
            {
               arguments[wordCount-1] = NULL;
            }

            standardCommand(arguments);
         }

         exit(0);
      }
      else if(pid>0)
      {
         close(onePipe[WRITE_END]);
         close(twoPipe[WRITE_END]);

         if(strcmp("&", arguments[wordCount-1]) != 0)
         {
            waitpid(pid, &status, 0);
         }

         read(twoPipe[READ_END], &shouldAdd, sizeof(shouldAdd));
         close(twoPipe[READ_END]);

         if(shouldAdd)
            addToHistory(lineInHeld);                                      //after command is finished (or is running in parallel), adds line to history

         read(onePipe[READ_END], &should_run, sizeof(should_run));
         close(onePipe[READ_END]);
      }
   }
}

/* Reads in a line from the user and returns it.
   Ignores any white space at the beginning of the line. */
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
      }
      else if (charSeen == false && charIn != ' ')
      {
         charSeen = true;
         lineIn[index] = charIn;
         index++;
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

/* Divides the given line into an array of strings by white space.
   Each string is an individual argument in the given line */
char** breakLineArguments(char line[])
{
   char* temp = strtok(line, " ");

   while (temp) 
   {
      wordCount++;
      lineNew = realloc (lineNew, sizeof (char*) * wordCount);

      if (lineNew == NULL)
         exit (-1); 

      lineNew[wordCount-1] = temp;

      temp = strtok (NULL, " "); 
   }

   lineNew = realloc (lineNew, sizeof (char*) * (wordCount+1));
   lineNew[wordCount] = '\0';

   return lineNew;
}

/* When the arguments consist of a standard command, this will
   call execvp and execute the command */
void standardCommand(char** arguments)
{
   execute(arguments[0], arguments);
}

/* Adds the given line to the history array */
void addToHistory(char line[])
{
   lineHistory = realloc (lineHistory, sizeof(char*) * linesInHistory+1);

   if (lineHistory == NULL)
      exit (-1);   

   lineHistory[linesInHistory] = line;
   linesInHistory++;
}

void runFromHistory(int marker)
{
   int location;

   if (linesInHistory > HISTORY)
   {
      location = (linesInHistory - marker) + (linesInHistory - HISTORY);
   }
   else
   {
      location = linesInHistory - marker;
   }
   char* line = lineHistory[location];
   char* temp = strtok(line, " ");
   char** lineNew2 = NULL;
   int wordCount2 = 0;

   while (temp) 
   {
      wordCount2++;
      lineNew2 = realloc (lineNew, sizeof (char*) * wordCount2);

      if (lineNew2 == NULL)
         exit (-1); 

      lineNew2[wordCount2-1] = temp;

      temp = strtok (NULL, " "); 
   }

   lineNew2 = realloc (lineNew2, sizeof (char*) * (wordCount2+1));
   lineNew2[wordCount2] = '\0';

   standardCommand(lineNew2);
}

/* Actually executes the command */
void execute(const char *binary, char *const arguments[])
{
   if (execvp(binary, arguments) < 0)
   {
      perror("Could not execute command.");
   }
}

