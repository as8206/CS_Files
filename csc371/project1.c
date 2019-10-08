#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//TODO close the files

void inputData();
void editData();
void printData();

int numOfEntrys;

char* filename = "fun.dat";

int main(void)
{
   system("clear");

   int inputChoice;
   char c;

   FILE *fptr;
   fptr = fopen(filename,"r");
   fseek(fptr, 0, SEEK_SET);

   int charCount = 0;
   int charTest;
   while((charTest=fgetc(fptr)) != EOF)
   {
      charCount++;
   }
   numOfEntrys = charCount / 16;
   printf("Num of entries: %d\n", numOfEntrys); //TODO remove and replace with file close

   while(inputChoice != 4)
   {
      inputChoice = -1;

      printf("Would you like to [1] add, [2] edit, [3] view the data, or [4] exit:\n");
      while(inputChoice != 1 && inputChoice != 2 && inputChoice != 3 && inputChoice != 4)
      {
         scanf("%d", &inputChoice);
         while((c=getchar()) != '\n' && c != EOF);
      }

      if(inputChoice == 1)
         inputData();
      else if(inputChoice == 2)
         editData();
      else if(inputChoice == 3)
         printData();
   }  

   return 0;
}

void inputData()
{
   system("clear");

   int inputHour, inputMinute, inputAge = -1;
   char inputName[8];

   FILE *fptr;
   fptr = fopen(filename,"a+");

   time_t curTime;
   struct tm * timeinfo;

   printf("Please enter your name: \n");
   char tempChar;
   int count = 0;
   while(count < 7 && (tempChar = getchar()) != '\n')
   {
      inputName[count] = tempChar;
      count++;
   }
   while(count < 7)
   {
      inputName[count] = ' ';
      count++;
   }
   inputName[count] = '\0';

   int c = tempChar;
   while(c != '\n')
   {
      c = getchar();
   }

   while(inputAge < 0 || inputAge > 999)
   {
      printf("Please enter your age: \n");
      scanf("%d", &inputAge);
   }
   
   time(&curTime);
   timeinfo = localtime(&curTime);

   fprintf(fptr,"%7s%3d%02d:%02d\n",inputName, inputAge, timeinfo->tm_hour, timeinfo->tm_min);
   fclose(fptr);

   printf("%s, %d, ", inputName, inputAge);
   printf("%d:%d\n", timeinfo->tm_hour, timeinfo->tm_min);

   system("clear");
   return;
}

void editData()
{
   system("clear");

   int entryNum, editLocation = 0, inputChoice = -1;
   char inputName[8];

   FILE *fptr;
   fptr = fopen(filename,"r+");

   printf("Which data entry would you like to edit:\n");
   scanf("%d", &entryNum);

   editLocation = 16 * (entryNum - 1);
   
   system("clear");
   printf("Editing entry #%d\n", entryNum);
   while (inputChoice < 1 || inputChoice > 3)
   {
      printf("Would you like to edit the [1] name, [2] age, or [3] time entered:\n");
      scanf("%d", &inputChoice);
   }

   int c;
   while((c=getchar()) != '\n' && c != EOF);

   if(inputChoice == 1)
   {
      printf("Please enter new name:\n");
      char tempChar;
      int count = 0;
      while(count < 7 && (tempChar = getchar()) != '\n')
      {
         inputName[count] = tempChar;
         count++;
      }
      while(count < 7)
      {
         inputName[count] = ' ';
         count++;
      }
      inputName[count] = '\0';

      int c = tempChar;
      while(c != '\n')
      {
         c = getchar();
      }

      fseek(fptr, editLocation, SEEK_SET);
      fprintf(fptr, "%s", inputName);
   }
   else if(inputChoice == 2)
   {
      editLocation = editLocation + 7;

      printf("Please enter new age:\n");
      int newAge;
      scanf("%d", &newAge);

      fseek(fptr, editLocation, SEEK_SET);
      fprintf(fptr, "%3d", newAge);
   }
   else if(inputChoice == 3)
   {
      editLocation = editLocation + 10;
      
      int newHour, newMinute;
      printf("Please enter new hour value:\n");
      scanf("%d", &newHour);
      printf("Please enter new minute value:\n");
      scanf("%d", &newMinute);

      fseek(fptr, editLocation, SEEK_SET);
      fprintf(fptr, "%2d:%2d", newHour, newMinute);     
   }
   while((c=getchar()) != '\n' && c != EOF);
   system("clear");
   return;
}

void printData()
{
   FILE *fptr;
   fptr = fopen(filename,"r");
   fseek(fptr, 0, SEEK_SET);
   char currentChar;

   for(int line = 0; line < numOfEntrys; line++)
   {
      printf("%3d: ", line+1);
      for(int indent = 0; indent < 16; indent++)
      {
         currentChar = fgetc(fptr);
         printf("%c", currentChar);
         if(indent == 6 || indent == 9)
            printf(" | ");
      }
   }
}




