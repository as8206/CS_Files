/* Lab: Lab 4
   Programmer: Spencer Hooper, Andrew S. and Christian G.
   Professor: Dr. Lee
   File Created: 02/14/2017
   File Updated: 02/14/2017
*/

#include "lab4.h"     //lab4.h is the directory we will be pulling information                          from
int lab4b(int i)     //initializes integer i within lab4b
{
   int s;     //initializes integer s
   s = (i * (i + 1))/ 2;     //finds half the product of an integer and the next                               positive integer
   return s;     //returns s
}
