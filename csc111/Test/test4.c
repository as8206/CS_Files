#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct{
   union{
     char a, b;
     int c;
   }d;
   int e[5];
}f, *p = &f;

int main()
{
   fgetc(stdin);
}
