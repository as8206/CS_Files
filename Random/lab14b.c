#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab14.h"

#define MAX_LEN 50
int glo_track = MAX_LEN;

int reduceString(char *string, FILE *keyFile, int numOfKey)
{
  // char *string = "aabaab";
  // char *key[MAX_LEN] = {"aa", "ba", "bb"};
  // int numOfKey = 3;
   char key[MAX_LEN][MAX_LEN];
   int i;
   char *keys[MAX_LEN];
   
   rewind(keyFile);
   for (i = 0; i < numOfKey; i++)
   {
      fgets(key[i], sizeof(key[i]), keyFile);
      strtok(key[i], "\n");
   }
/*   for(i = 0; i < numOfKey; i++)
   {
      strcpy(keys[i], key[i]);
   }*/
   for(i = 0; i < strlen(string); i++)
   {
      removeIfMatch(string, i, keys, numOfKey);
   }

   printf("%d\n", glo_track);
   return glo_track;
}

void removeIfMatch(char *str, int pos, char key[], int numOfKey)
{
   char *localStr = str;
   int i, j;
   for (j = 0; j < numOfKey; j++)
   {
      if (checkForMatch(localStr, pos, key[j]))
      {
         if (glo_track == 0)
            return;

         localStr = removeMatch(localStr, pos, key[j]);
         if (strlen(localStr) < glo_track)
            glo_track = strlen(localStr);
         for (i = 0; i < strlen(localStr); i++)
         {
            removeIfMatch(localStr, pos, key, numOfKey);
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
      for (j = pos; str[j] != '\0'; j++)
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
