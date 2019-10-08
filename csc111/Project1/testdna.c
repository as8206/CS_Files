/* Project 1: testdna.c
   Programmer: Andrew Stake
   Class: CS2
   Professor: Dr. Lee
   File Created: March 21, 2017
   File Updtated: March 22, 2017
*/

#include<stdio.h>
#include<stdlib.h>
#include"testdna.h"

void insert(char);
void printout();
int checkLength(char*);

#define DNA_LEN 25                     //maximum size of dna sequence     

struct DNA *first = NULL;              //creates pointer to use as the pointer to the first element in the list   

int main()
{
   char DNAsequence[DNA_LEN+1];
   char DNAbase;
   int i;
   int lessThanMaxLen = 0;
   
   while(!lessThanMaxLen)              //Gets input from user, and checks it is of the correct lenght. If not, requests again.
   {
      printf("Enter a DNA sequence:\n");
      scanf(" %[^\n25]s", DNAsequence);
      lessThanMaxLen = checkLength(DNAsequence);
      if(!lessThanMaxLen)
         printf("List is FULL. Nothing inserted.\n");
   }
   DNAbase = DNAsequence[0];
   for(i = 0; DNAbase != '\0'; DNAbase = DNAsequence[i])
   {
      insert(DNAbase);                 //transfers data from array to linked list
      i++;
   }
   printout();                         //passes to function to print the sequence that was entered
   countBase(first);                   //passes to countBase functiono to finish analysis
   return 0;
}

void insert(char DNAbase)              //given a character array, will transfer all characters into a linked list
{
   struct DNA *cur, *prev, *new_node;

   new_node = malloc(sizeof(struct DNA));
   if (new_node == NULL)
   {
      printf("Memory is full error");
      return;
   }

   new_node->base = DNAbase;
   
   for(cur = first, prev = NULL; cur != NULL; prev = cur, cur = cur->next);

   if(prev == NULL)
      first = new_node;
   else
      prev->next = new_node;
}

void printout()                        //prints the linked list sequence
{
   struct DNA *Print = first;
   printf("Sequence: ");
   while(Print != NULL)                //runs until the end of the linked list
   {
      printf("%c", Print->base);
      Print = Print->next;
   }
   printf("\n");
}

int checkLength(char* Sequence)        //ensures sequence of the of the correct length by ensuring the end string character is present
{
   int i;
   int correct = 0;
   for(i = 0; i < DNA_LEN + 1; i++)
   {
      if(Sequence[i] == '\0')
      {
         correct = 1;
      }
   }
   return correct;                    //returns true if sequence is less than 25 characters
}
