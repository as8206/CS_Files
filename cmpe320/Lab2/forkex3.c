#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<string.h>

typedef int boolean;
#define true 1
#define false 0

const char* commandLine;

void execute(const char *binary, char *const arguments[], char *const envp[])
{
   if (execve(binary, arguments, envp) < 0)
   {
      perror("Could not execute command.");
   }
}

const char* parseLine(int startIndex, const char* String)
{
   int newStringSize = 128, index = 0;
   char* newString = malloc(newStringSize);
   char charIndex = 't';
   boolean charSeen = false;
   while (charIndex != EOF && charIndex != '\n')
   {
      charIndex = String[startIndex];
      if (index >= newStringSize)
      {
         newStringSize = newStringSize * 2;
         newString = realloc(newString, newStringSize);
      }
      if (charSeen == true)
      {
         newString[index] = charIndex;
         index++;
         startIndex++;
      }
      else if (charSeen == false && charIndex != ' ')
      {
         charSeen = true;
         newString[index] = charIndex;
         index++;
         startIndex++;
      }
      else if (charSeen == false && charIndex == ' ')
      {
         startIndex++;
      }
   }
   int len = strlen(newString);
   return newString;
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
      }
      else if (charSeen == false && charIn != ' ')
      {
         charSeen = true;
         lineIn[index] = charIn;
         index++;
      } 

      charIn = getc(stdin);
   }

   if (index >= size+2)
   {
      size = size + 128;
      lineIn = realloc(lineIn, size);
   }
   lineIn[index] = ' ';
   lineIn[index+1] = '.';
   lineIn[index+2] = EOF;
    
   return lineIn;
}
int countArguments(const char* commandLine)
{
   char charIndex = 't';
   int index = 0, wordCount = 0;
   boolean spaceSeen = true;

   while (charIndex != EOF && charIndex != '\n')
   {
      charIndex = commandLine[index];
      if (charIndex == ' ')
      {
         spaceSeen = true;
      }
      else if (charIndex != ' ' && spaceSeen == true)
      {
         wordCount++;
         spaceSeen = false;
      }
      index++;
   }
   return wordCount-1;
}

const char* nextArgument(const char* currentString)
{
   char charIndex = 't';
   int index = 0;
   boolean charSeen = false;
   int argSize = 128;
   char* argument = malloc(argSize);

   while (charIndex != EOF && charIndex != '\n')
   {
      charIndex = currentString[index];
      if (charIndex == ' ' && charSeen == true)
      {
         if (index >= argSize)
         {
            argSize = argSize * 2;
            argument = realloc(argument, argSize);
         }
         argument[index] = '\0';
         commandLine = parseLine(index, currentString);
         return argument;
      }
      else if (charIndex != ' ')
      {
         if (index >= argSize)
         {
            argSize = argSize * 2;
            argument = realloc(argument, argSize);
         }
         argument[index] = charIndex;
         charSeen = true;
      }
      index++;
      
   }
   return currentString;
}

char** buildCommandLine()
{
   int wordCount = countArguments(commandLine);
   int size = 128;
   char** argumentList = malloc(wordCount);
   for(int i = 0; i < wordCount; i++)
   {
      argumentList[i] = malloc(size);
      argumentList[i] = nextArgument(commandLine);
   }
   return argumentList;
}

int main(int argc, char **argv, char **envp)
{
   printf("Please enter your command:\n");

   commandLine = readLine();                  //Sets the command line equal to the input line
   for (int i = 0; i < strlen(commandLine); i++)
   {
      printf("%c", commandLine[i]);
   }

   int wordCount = countArguments(commandLine);
   char** argumentList = buildCommandLine(commandLine);
   
   char* command = malloc(5+strlen(argumentList[0]));
   strcpy(command, "/bin/");
   strcat(command, argumentList[0]);
   
   argumentList[0] = command;

   char** arguments = malloc(wordCount+2);
   int i = 0;
   while (i < wordCount)
   {
      arguments[i] = malloc(128);
      arguments[i] = argumentList[i];
      i++;
   }
/*   arguments[i] = "-1";
   i++;
   arguments[i] = 0x00;
*/
   //Here is where the old code starts, use this to access the commands
   pid_t pid = fork();

   if (pid<0) {
      perror("Error: fork failed.");
      exit(-1);
   }

   if (pid == 0) {
      if (argc == 0)
         argv[1] = "./";
 
      execute(command, arguments, envp);

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
