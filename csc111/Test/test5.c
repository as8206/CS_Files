#include<stdio.h>
#include<stdlib.h>

#define N 10

int main()
{
   FILE *fp;
   char ch;  
 
   fp = fopen("input.dat", "w+");
   for(ch='A'; ch<'Z';ch++)
   {
      fwrite (&ch, sizeof(char), 1, fp);
   }
   rewind(fp);
   fseek(fp, 1, 0);
   fread(&ch, 1, 1, fp);
   printf("%c\n", ch);

  fclose(fp);
  return 0;
}
