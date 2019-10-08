#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef enum {ONE = 1, TWO = 2} NUM;

typedef union
{
   char num1;
   int num2;
} UNUM;

typedef struct
{
   float fb;
   NUM num;
   UNUM f;
   float fa;
} SNUM;

int main()
{
   SNUM *snum;
   snum = malloc(sizeof(SNUM));
   snum->num->num1 = 'a';
   printf("%c\n", snum->num->num1);
}
