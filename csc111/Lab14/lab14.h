/* Lab 14: Lab14.h
   Programmers: Andrew S, Mike S, Spencer H
   Class: CS2
   Professor: Dr. Lee
   File Created: April 20, 2017
   File Updated: April 20, 2017
*/

int checkForMatch(char *str, int pos, char *key);
void removeIfMatch(char *str, int pos, FILE *keyFile, int numOfKey);
char* removeMatch(char *str, int pos, char *key);
int reduceString(char *string, FILE *keyFile, int numOfKey);
