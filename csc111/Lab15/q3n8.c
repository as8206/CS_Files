#include <stdio.h>
#define N 10
#define M 3

int main()
{
   FILE *fp;                             //creates file pointer
   int i;
   long int pt;
   
   fp = fopen("input.dat", "w+");        //opens file "input.dat", if file does not already exist, it is created.
   for (i = 1; i < N; i++)
   {
      fwrite (&i, sizeof(int), 1, fp);   //writes i to the file until loop terminates
   }
   pt = ftell(fp);                       //sets pt equal to the current file position
   printf("%ld\n", pt);
   pt -= M* sizeof(int);                 //moves pt back 4 integers in the file
   printf("%ld\n", pt);

   
   fseek(fp, pt, 0);                     //moves the file position to the beginning and then pt to the right
   fread(&i, sizeof(int), 1, fp);        //reads the number at the current position and stores it in i
   printf("%d\n", i);                    //prints out the value of i
   
   fclose(fp);
   return 0;
}
