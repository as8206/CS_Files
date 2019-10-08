#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>

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
      //printf("parse loop: %d Char: %c\n", index, String[startIndex]);
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
   printf("newString: %s\n", newString);
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

   if (index >= size)
   {
      size = size + 128;
      lineIn = realloc(lineIn, size);
   }
   lineIn[index] = EOF;
   
   return lineIn;
}
int countArguments(const char* commandLine)
{
   char charIndex = 't';
   int spaceCount = 0, index = 0, wordCount = 0;
   boolean spaceSeen = true;

   while (charIndex != EOF && charIndex != '\n')
   {
      charIndex = commandLine[index];
      if (charIndex == ' ')
      {
         spaceCount++;
         spaceSeen = true;
      }
      else if (charIndex != ' ' && spaceSeen == true)
      {
         wordCount++;
         spaceSeen = false;
      }
      index++;
   }
   return wordCount;
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
      //printf("next arg loop: %d\n", index);
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
         printf("%c\n", argument[1]);
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
         printf("added char: %c\n", argument[index]);
         charSeen = true;
      }
      index++;
      
   }
   return currentString;
}

int main(int argc, char **argv, char **envp)
{
   printf("Please enter your command:\n");
   /*
   int size = 128, index = 0;
   char* lineIn = malloc(size);
   char charIn = getc(stdin);
  
   while (charIn != EOF && charIn != '\n')            //Reads in the user input on the command line and dynamically allocates space to allow for variable length input
   {
      if (index >= size)
      {
         size = size + 128;
         lineIn = realloc(lineIn, size);
      }
      lineIn[index] = charIn;
      index++;
      charIn = getc(stdin);
   }

   if (index >= size)
   {
      size = size + 128;
      lineIn = realloc(lineIn, size);
   }
   lineIn[index] = EOF;                               //Ends the string with an EOF marker
*/

   commandLine = readLine();                  //Sets the command line equal to the input line
   printf("Command: %s\n", commandLine);
   int wordCount = countArguments(commandLine);
   printf("wordCount: %d\n", wordCount);
   char* testLine = nextArgument(commandLine);
   printf("testLine: %s\n", testLine);
   printf("Command: %s\n", commandLine);
   testLine = nextArgument(commandLine);
   printf("testLine: %s\n", testLine);

   //Here is where the old code starts, use this to access the commands
   pid_t pid = fork();

   if (pid<0) {
      perror("Error: fork failed.");
      exit(-1);
   }

   if (pid == 0) {
      if (argc == 0)
         argv[1] = "./";
 
      char *arguments[4] = { "/bin/ls", argv[1], "-1", 0x00 };  //Add extra argument after bin/ls to change directory

      execute("/bin/ls", arguments, envp);

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
