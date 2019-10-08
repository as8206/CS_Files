/*CSC111: Computer Science 2
  Lab 13: lab13.c
  Programmers: Andrew S and Mike S
  Professor: Dr. Lee
  File Created: April 13, 2017
  File Updated: April 13, 2017 
*/

#include <stdio.h>
#include <string.h>
#include "lab13.h"



#define MAX_SIZE 50                              //defines the maximum size of the string

int main()
{
   Bool foundVowel = FALSE;
   char str[MAX_SIZE], strOriginal[MAX_SIZE];
   int i;
   
   printf("Enter a string: ");
   scanf("%s", str);                             //reads in the input string from the user
   strcpy(strOriginal, str);                     //stores the input in its original form
   strcat(str, "- ");                            //adds "- " to the end for formatting

   if(startsWithVowel(str))                      //checks if the string already starts with a vowel and adds "way" to the end if it does
   {
      strcat(str, "way");
      foundVowel = TRUE;
   }
   else
   {
      moveChar(str);                             //calls the moveChar function
      for(i = 0; i < strlen(str); i++)           //runs through the entire string
      { 
         if(startsWithVowel(str))                //if it now begins with a vowel, adds "ay" and breaks out of the for loop
         {
            strcat(str, "ay");
            foundVowel = TRUE;
            break;
         }
         else
            moveChar(str);                       //else it moves the characters again
      }
   }

   if(!foundVowel)                               //if no vowel was found, checks to find the first y
   {
      for(i = 0; i < strlen(str); i++)
      {
         if(checkForY(str))                      //if a y is found, adds "ay" tothe end and escapes the for loop
         {
            strcat(str, "ay");
            foundVowel = TRUE;
            break;
         }
         else if (i != strlen(str) - 1)          //else moves the characters, unles at the end of the string
         {
            moveChar(str);
         }
      }
   }

   if(!foundVowel)                               //if now vowels or a y is found, "way" is added to the end of the string
     strcat(str, "way");

   printf("The pig Latin form of %s is: %s\n", strOriginal, str);

   return 0;
}

Bool startsWithVowel(char *str)                   //checks to see if the string begins with vowel
{
   if(str[0] == 'a' || str[0] == 'e'|| str[0] == 'i'|| str[0] == 'o'|| str[0] == 'u'|| str[0] == 'A'|| str[0] == 'E'|| str[0] == 'I'|| str[0] == 'O'|| str[0] == 'U')
      return TRUE;                                  //if begins with a vowel, returns 1 (true)
   else
      return FALSE;                                  //else the function will return 0 (false)
}

Bool checkForY(char *str)                         //checks if the string begins with a y
{
   if(str[0] == 'y' || str[0] == 'Y')            //if the first character is a y, returns 1 (true)
      return TRUE;
   else                                          //else the function will return 0 (false)
      return FALSE;
}

void moveChar(char *str)                         //shifts the first character to be the last character in the string
{
   char temp = str[0];                           //character variable to temporarily hold the first character
   int i;
   
   for(i = 0; i < strlen(str); i++)              //runs through the entire character array
   {
      str[i] = str[i+1];                         //shifts all of the characters to the left
   }   
   str[strlen(str)] = temp;                      //stores what was the first character, in the last position of the array
}
