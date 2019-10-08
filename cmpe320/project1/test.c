#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<string.h>

char str[];
char ** res  = NULL;
int n_spaces = 0, i;

void token();

int main()
{
   str = "ls -l";
   token();
   for (i = 0; i < (n_spaces+1); ++i)
     printf ("res[%d] = %s\n", i, res[i]);
}

void token(){
/* split string and append tokens to 'res' */

char *  p    = strtok (str, " ");
while (p) {
  res = realloc (res, sizeof (char*) * ++n_spaces);

  if (res == NULL)
    exit (-1); /* memory allocation failed */

  res[n_spaces-1] = p;

  p = strtok (NULL, " ");
}

/* realloc one extra element for the last NULL */

res = realloc (res, sizeof (char*) * (n_spaces+1));
res[n_spaces] = 0;

/* print the result */

for (i = 0; i < (n_spaces+1); ++i)
  printf ("res[%d] = %s\n", i, res[i]);

/* free the memory allocated */


}
