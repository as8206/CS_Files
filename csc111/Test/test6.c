#include <stdio.h>
#include <stdlib.h>

int main()
{
   int i = 0xA121;
   int j = 0x0FF0;

   printf("%#08x\n", i & j);
   printf("%#08x\n", i | j);
   printf("%#08x\n", i ^ j);

   return 0;
}
