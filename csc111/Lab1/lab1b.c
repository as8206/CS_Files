/* CSC111 Computer Science II
   Lab1 1 Getting to Know Linux: lab1b.c
   Programmer: Andrew Stake
   Professor: Dr. Lee
   File Created: Jan 26, 2017
   File Updated: Jan 26, 2017
*/

#include<stdio.h>

int main(int argc, char *argv[])
{
   int i;
   printf("Input? ");
   scanf("%d", &i);                      //reads an integer; stores into i
   printf("What is the value of i? %d\n", i);
   printf("argc? %d\n", argc);          //print out the value of argc
   printf("argv[0]? %s\n", argv[0]);    //print out the value of argv[0]
   printf("argv[1]? %s\n", argv[1]);    //print out the value of argv[1]
   printf("argv[2]? %s\n", argv[2]);    //print out the value of argv[2]
   return 0;
}
