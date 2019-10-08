/* Project 1: testdna.h
   Programmer: Andrew Stake
   Class: CS2
   Professor: Dr. Lee
   File Created: March 21, 2017
   File Updated: March 22, 2017
*/

struct DNA {                           //creates the structure to hold the DNA linked list structure
   char base;
   struct DNA *next;
};

void countBase(struct DNA*);
