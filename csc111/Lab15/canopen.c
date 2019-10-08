/*CSC 111: Computer Science 2
 *Lab 15: File Operations: Input/output
 *Programmers: Mike, Andrew, & Spencer
 *Date Created: 4/20/17
 *Date Updated: 4/20/17
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

  FILE *fp;                                    //creates a pointer for the given file

  if (argc != 2){                              //checks if user gave the correct amount of input, if not, gives message and exits program
    printf("Usage: canopen filename\n");
    exit(EXIT_FAILURE);
  }
  
  if ((fp = fopen(argv[1], "r")) == NULL) {    //checks if the file can be opened, if not, informs user and exits program
    printf("%s can't be opened\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  printf("%s can be opened\n", argv[1]);       //informs user the file can be opened
  fclose(fp);                                  //closes the open file
  return 0;
}
