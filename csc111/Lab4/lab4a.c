/* Lab: lab 4
   Programmer: Christian Crouthamel Group: Andrew S. and Spencer H. 
   Class: CS2 
   Professor: Dr. Lee
   File Created: 02/14/17
   File Updated: 02/14/17
*/

  #include "lab4.h" //brings information from the lab4.h file 

  int lab4a(int n)   //integer parameter n to be used in the function
{
   int i;         //variable i declaration
   int s = 0;     //variable s declared and intialized with value 0
  
   for (i=1; i <= n; i++)     //int i is intialized in for loop to execute n times 
   {
      s = i+s;                //the variable s gets the value of i + s
   }
  return s;                  //returns the value of s
}   
