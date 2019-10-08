/* CSC111 Computer Science II
   Lab 8 readline.h
   Programmers: Kent Solenberger & Andrew Stake
   Professor: Dr. Lee
   File Created: Mar 7, 2017
   File Updated: Mar 7, 2017
*/

#include <ctype.h>
#include <stdio.h>
#include "readline.h"

int read_line(char str[], int n)
{
   int ch, i=0;

   while(isspace(ch=getchar()))
      ;
   while(ch!='\n' && ch!=EOF)
   {
      if(i<n)
         str[i++]=ch;
      ch=getchar()
   }
   str[i]='\0';
   return i;
}
