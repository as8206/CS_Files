/* Lab 14: Lab14b.c
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

#define MAX_LEN 55
int glo_track = MAX_LEN;
int glo_run = 0;

int reduceString(char *string, FILE *keyFile, int numOfKey)
{
  // char *string = "aabaab";
  // char *key[MAX_LEN] = {"aa", "ba", "bb"};
  // int numOfKey = 3;
   glo_track = strlen(string);
   char key[MAX_LEN][MAX_LEN];
   int i;
   
   rewind(keyFile);
   for (i = 0; i < numOfKey; i++)
   {
      fgets(key[i], sizeof(key[i]), keyFile);
      strtok(key[i], "\n");
   }

   for(i = 0; i < strlen(string); i++)
   {
      removeIfMatch(string, i, keyFile, numOfKey);
   }

   return glo_track;
}

void removeIfMatch(char *str, int pos, FILE *keyFile, int numOfKey)
{
   char *localStr = str;
   int i, j;
   char key[MAX_LEN][MAX_LEN];

   rewind(keyFile);
   for (i = 0; i < numOfKey; i++)
   {
      fgets(key[i], sizeof(key[i]), keyFile);
      strtok(key[i], "\n");
   }

   for (j = 0; j < numOfKey; j++)
   {      
//      printf("Local String: %s Position: %d Current Key: %s\n", localStr, pos, key[j]);
      if (checkForMatch(localStr, pos, key[j]))
      {
         if (glo_track == 0){
            return;
         }

         localStr = removeMatch(localStr, pos, key[j]);
         if (strlen(localStr) < glo_track)
            glo_track = strlen(localStr);
         for (i = 0; i < strlen(localStr); i++)
         {
//            printf("New String: %s\n", localStr);
            glo_run++;
            removeIfMatch(localStr, i, keyFile, numOfKey);
         }
      }
   }
   
   return;
}

int checkForMatch(char *str, int pos, char *key)
{
   int i;
   char checkStr[MAX_LEN];
  
   for (i = 0; i < strlen(key); i++)
   {
      checkStr[i] = str[pos+i];
   }
//   printf("Comparison String: %s Key: %s\n", checkStr, key);
   for (i=0; i < strlen(key); i++)
   {
      if(checkStr[i] != key[i])
         return 0;
   }
   return 1;

}     

char* removeMatch(char *str, int pos, char *key)
{
   int i, j, x;
   char temp[MAX_LEN];
   for (i = 0; i < strlen(key); i++)
   {
      x = 0;
      for (j = 0; str[j] != '\0'; j++)
      {
         if (j!=pos)
         {
            temp[x] = str[j];
            x++;
         }
      }
      temp[x] = '\0';
      str = temp;
   }
   return str;
}
