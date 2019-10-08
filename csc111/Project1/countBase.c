/* Project 1; countBase.c
   Programmer: Andrew Stake
   Class: CS2
   Professor: Dr. Lee
   File Created: March 21, 2017
   File Updated: March 22, 2017
*/
#include<stdio.h>
#include<stdlib.h>
#include"testdna.h"

void countBase(struct DNA *Seq)                  //takes a pointer to a DNA list and counts how many of each base there are. 
{
   int numOfA = 0, numOfC = 0, numOfT = 0, numOfG = 0;
   struct DNA *Prev = NULL;

   while(Seq != NULL)
   {
      if(Seq->base == 'a' || Seq->base == 'A')
         numOfA++;
      else if(Seq->base == 'c' || Seq->base == 'C')
         numOfC++;
      else if(Seq->base == 't' || Seq->base == 'T')
         numOfT++;
      else if(Seq->base == 'g' || Seq->base == 'G')
         numOfG++;
      else
         printf("Invalid base %c\n", Seq->base); //if base is not a true DNA base, reports what the incorrect character is
      Prev = Seq;
      Seq = Seq->next;                           //moves to the next item in the list
      free(Prev);                                //frees the memory location of the previous location
   }

   printf("Number of A's : %d\n", numOfA);       //prints the amount of each base 
   printf("Number of C's : %d\n", numOfC);
   printf("Number of T's : %d\n", numOfT);
   printf("Number of G's : %d\n", numOfG);
}
