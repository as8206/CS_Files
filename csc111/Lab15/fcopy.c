/* CSC111 Computer Science II
   Professor: Dr. Lee
   Programmers: Spencer Hooper, Mike S and Andrew S
   File Created: 20 April 2017
   File Updated: 20 April 2017
*/
/* Copies  a file */

#include <stdio.h>
#include <stdlib.h>


int main (int argc, char *argv[])
{
   FILE *source_fp, *dest_fp;                          //creates file pointers to be used on the given file and the new file
   int ch;
   
   if (argc != 3) {                                    //checks if the user gives the correct amount of input, if not, prints message and exits program
      fprintf(stderr, "usage: fcopy source dest\n");
      exit(EXIT_FAILURE);
   }

   if ((source_fp = fopen(argv[1], "rb")) == NULL) {   //checks if the file can be opened, if not, gives error message and exits program
      fprintf(stderr, "Can't open %s\n", argv[1]);
      exit(EXIT_FAILURE);
   }

   if ((dest_fp = fopen (argv[2], "wb")) == NULL) {    //checks if the file can be opened, if no, gives error message and exits program
      fprintf(stderr, "Can't open %s\n", argv[2]);
      fclose(source_fp);
      exit(EXIT_FAILURE);
   }

   while ((ch = getc(source_fp)) != EOF)               //goes through and copieseach character over to the new file, until the end of the original is reached
      putc(ch, dest_fp);

   fclose(source_fp);                                  //closes the files
   fclose(dest_fp);
   return 0;
}
