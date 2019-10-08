/* Lab 12: xor.c
   Programmer: Andrew S & Jessica H.
   Class: CS2
   Professor: Dr. Lee
   File Created: April 11, 2017
   File Updated: April 11, 2017
*/

#include <ctype.h>
#include <stdio.h>

#define KEY '&'

int main(void)
{
   int orig_char, new_char;                         //variables to hold the unencrypted and newly encrypted characters

   while ((orig_char = getchar()) != EOF)           //runs through the input file character by character until the end of the file 
   {
      new_char = orig_char ^ KEY;                   //encrypts the current character, storing it in new_char
      if (isprint(orig_char) && isprint(new_char))  //checks if the new character is able to be printed, stores that if it can be, stores original if it can't
         putchar(new_char);
      else
         putchar(orig_char);
   }
  
   return 0;
}
