/* lab12: viewmemory.c
:  Progammers: Jessica Harshbarger & Andrew S.
   Class: CSC2
   Professor: Dr. Lee
   File created: April 11, 2017
   File updated: April 11, 2017
*/

#include <ctype.h>
#include <stdio.h>

typedef unsigned char BYTE;

int main()
{
  unsigned int addr;                     //variable to hold the user defined memory address
  int i, n;
  BYTE *ptr;

  printf("Address of the main function: %x\n", (unsigned int) main);
  printf("Address of the addr variable: %x\n", (unsigned int) &addr);
  printf("\nEnter a (hex) adress: ");
  scanf("%x", &addr);                    //gets the address from the user
  printf("Enter number of bytes to view: ");
  scanf("%d", &n);                       //gets the amount of bytes the user would like to see from the user

  printf("\n");
  printf(" Address              Bytes             Characters\n");
  printf(" -------  ----------------------------  ----------\n");

  ptr = (BYTE *) addr;                   //sets the pointer equal to the address specified by the user 
  for (; n > 0; n -= 10) {
    printf("%8X ", (unsigned int) ptr);  //prints the current address viewed in memory
    for (i = 0; i < 10 && i < n; i++)    //goes and prints 10 bytes from that address or until n is finished
      printf("%.2X ", *(ptr + i));
    for (; i < 10; i++)                  //if n is not a multiple of 10, fills remaining spaces with blanks
      printf(" ");
    printf(" ");
    for (i = 0; i < 10 && i < n; i++) {  //prints the character representation of the value of that byte
      BYTE ch = *(ptr + i);
      if (!isprint(ch))                  //checks to ensure the value of the byte is a printable character, if not, prints a "." instead.
        ch = '.';
      printf("%c", ch);
     }
     printf("\n");
     ptr += 10;                          //moves the pointer to the next adrress
   }
  return 0;
}
