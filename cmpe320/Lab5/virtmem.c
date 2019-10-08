/*
 * Lab 5: Virtual Memory
 * Programmer: Andrew Stake
 * Course: CMPE 320
 * Section 2
 * Instructor: S. Lee
 */

#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

#define TLB_SIZE 16
#define PAGES 256
#define PAGE_MASK 255

#define PAGE_SIZE 256
#define OFFSET_BITS 8
#define OFFSET_MASK 255

// Max number of characters per line of input d
#define BUFFER_SIZE 10

typedef int bool;
#define true 1
#define false 0

int pageTable[PAGES];
int TLB[TLB_SIZE][2];
char memory[PAGES*PAGE_SIZE];
int frameRef = 0;
int TLBRef = 0;

int getPage(int value);
int getOffset(int value);
int pageFault(FILE* binaryFile, int page);
void updateTLB(int pageNum, int frameNum);

int main()
{
   int fileAddressesToRun;
   int page, offset, frame, physical, storedValue, binary = 0;
   int numOfTLBHits=0, numOfPageMisses=0;
   bool TLBHit = false;

   FILE* addressFile;
   addressFile = fopen("addresses.txt", "r");
   FILE* backingFile;
   backingFile = fopen("BACKING_STORE.bin", "rb");

   for(int i = 0; i < PAGES; i++)
   {
      pageTable[i] = -1;
   }

   printf("How many Addresses: ");
   scanf("%d", &fileAddressesToRun);

   if (fileAddressesToRun > 1000 || fileAddressesToRun < 1)
   {
      fprintf(stderr, "Error: Please enter a value number of addresses (1 - 1000).\n");
      return -1;
   }

   for (int i = 0; i < fileAddressesToRun; i++)
   {
      fscanf(addressFile, "%d", &binary);
      page = getPage(binary);
      offset = getOffset(binary);

      for (int j = 0; j < TLB_SIZE; j++)
      {
         if (TLB[j][0] == page)
         {
            frame = TLB[j][1];
            TLBHit = true;
            numOfTLBHits++;
         }                  
      }
      
      if(TLBHit == false && pageTable[page] != -1)
      {
         frame = pageTable[page];
         updateTLB(page, frame);         
      }
      else if(TLBHit == false)
      {
         frame = pageFault(backingFile, page);
         pageTable[page] = frame;
         numOfPageMisses++;
         updateTLB(page, frame);
      }
  
      physical = (frame*PAGE_SIZE) + offset;
      storedValue = memory[physical];

      printf("Virtual address: %d Physical address: %d Value: %d\n", binary, physical, memory[physical]);
      TLBHit = false;
   }
   printf("Number of Translated Addresses = %d\n", fileAddressesToRun);
   printf("Page Faults = %d\n", numOfPageMisses);
   printf("Page Fault Rate = %.3f\n", (double)numOfPageMisses/(double)fileAddressesToRun);
   printf("TLB Hits = %d\n", numOfTLBHits);
   printf("TLB Hit Rate = %.3f\n", (double)numOfTLBHits/(double)fileAddressesToRun);

   fclose(addressFile);
   fclose(backingFile);

   return 0;
}

int getPage(int value)
{
   return value >> OFFSET_BITS;
}

int getOffset(int value)
{
   return value & PAGE_MASK;
}

int pageFault(FILE* binaryFile, int page)
{
   long seekValue = page * PAGE_SIZE;
   fseek(binaryFile, seekValue, SEEK_SET);

   char temp;

   for(int i = 0; i < 256; i++)
   {
      fread(&temp, sizeof(char), 1, binaryFile);
      memory[(frameRef*PAGE_SIZE)+i] = temp;
   }

   frameRef++;
   return frameRef-1;
}

void updateTLB(int pageNum, int frameNum)
{
   TLB[TLBRef][0] = pageNum;
   TLB[TLBRef][1] = frameNum;

   TLBRef++;

   if (TLBRef > 15)
      TLBRef = 0;

   return;
}









