/* CSC111 Computer Science II
   Lab 8 readline.h
   Programmers: Kent Solenberger & Andrew Stake
   Professor: Dr. Lee
   File Created: Mar 7, 2017
   File Updated: Mar 7, 2017
*/

#ifndef READLINE_H
#define READLINE_H

/* readline: Skips leading white-space characters, then reads the remainder of
   the input line and stores it in str.  Truncates the line if its length 
   exceeds n.  Returns the number of characters stored. */
int read_line(char str[], int n);

#endif
