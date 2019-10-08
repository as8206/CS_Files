/* Lab 14: Lab14.c
   Programmers: Andrew S, Mike S, Spencer H
   Class: CS2
   Professor: Dr. Lee
   File Created: April 20, 2017
   File Updated: April 20, 2017
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab14.h"

#define MAX_LINES 55
#define FILE_NAME "result"
extern int glo_run;

int main(int argc, char *argv[])
{
   FILE *fp, *fp2;
   FILE *temp;
   char tempStr[MAX_LINES];
   char line[MAX_LINES];
   int keyNumber[MAX_LINES];
   char input[MAX_LINES][MAX_LINES];
   char keys[MAX_LINES][MAX_LINES][MAX_LINES];
   int i, j;
   int numOfCases = 0;

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
  
   fgets(line, sizeof(line), fp);
   for(i = 0; line[0] != '0'; i++)
   {
      keyNumber[i] = atoi(strtok(line, " "));
      strcpy(input[i], strtok(NULL, " "));
      for(j = 0; j < keyNumber[i]; j++)
      {
         strcpy(keys[i][j], strtok(NULL, " "));
      }

      fgets(line, sizeof(line), fp);
      numOfCases++;
   }
 
   fp2 = fopen(FILE_NAME, "w+");
   for (j = 0; j < numOfCases; j++)
   {
      temp = fopen("temp.dat", "w+");
      for (i = 0; i < keyNumber[j]; i++)
      {
         fputs(keys[j][i], temp);
         fputs("\n", temp);
      }
   

      sprintf(tempStr, "%d", reduceString(input[j], temp, keyNumber[j]));
//      printf("\nMinimum string length found: %s\n", tempStr);
//      printf("-----------------------------------------------------\n");
      fputs(tempStr, fp2);
      fputs("\n", fp2); 
      fclose(temp);
   }
   
   printf("Times removeIfMatch was recursively called: %d\n", glo_run);
   return 0;
}
      
