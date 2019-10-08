/* Lab7: charlist.c
   Programmer: Andrew Stake & David G
   Class: CS2
   Professor: Dr. Lee
   File Created: March 2, 2017
   File Updated: March 2, 2017
*/

#include"charlist.h"
#include<stdio.h>

/* iniialize the array pointed to by p so that it is ready to
   be a character list
*/

void initialize_list(char *p)
{
   *p = '\0';
}

/* print out the characters in the list */

void print_list(char *p)
{
   char *temp = p;
   while (*temp != '\0')
   {
      printf("%c", *temp);
      temp++;
   }
   printf("\n");
}

/* Add a character to the end of the list */

void add_to_list(char *p, char x)
{
   char *temp = p;
   while (*temp != '\0')
   {
      temp++;
   }
   *temp = x;
   temp++;
   *temp = '\0';
}

void delete_from_list(char *p)    //delete an item from the list at location p
{
   char *q = p+1;                 //creates variable to shift list
   for(;*p != '\0'; p++)
   {
      *p = *q;                    //moves all items after p to the down, overiding p
      q++;
   }
   *p = '\0';                     //fills last spot with null
} 
