/* Lab 16: airmiles.c
   Programmer: Andrew S and Mike S
   Class: CS2
   Professor: Dr. Lee
   File Created: April 25, 2017
   File Updated: April 25, 2017
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct city_info {                                         //creates the structure to hold the city name and distance in miles
   char *city;
   int miles;
};

int compare_cities(const void *key_ptr, const void *element_ptr);

int main()
{
   char city_name[81];                                     //creates a string to hold the user input
   struct city_info *ptr;                                  //creates a pointer to hold the return value from bsearch
   const struct city_info mileage[] =                      //creates and fills an array of structures
      {{"Berlin", 3965}, {"Buenos Aires", 5297},
       {"Cairo",  5602}, {"Calcutta", 7918},
       {"Cape Town", 7764}, {"Caracas", 2132},
       {"Chicago", 713}, {"Hong Kong", 8054},
       {"Honolulu", 4964}, {"Istanbul", 4975},
       {"Lisbon", 3364}, {"London", 3458},
       {"Los Angeles", 2451}, {"Manila", 8498},
       {"Mexico City", 2094}, {"Montreal", 320},
       {"Moscow", 4665}, {"Paris", 3624},
       {"Rio de Janeiro", 4817}, {"Rome", 4281},
       {"San Francisco", 2571}, {"Shanghai", 7371},
       {"Stockholm", 3924}, {"Sydney", 9933},
       {"Tokyo", 6740}, {"Warwaw", 4344},
       {"Washington", 205}};

   printf("Enter city name: ");
   scanf("%80[^\n]", city_name);                           //gets city from user input
   ptr = bsearch(city_name, mileage, sizeof(mileage) / sizeof(mileage[0]), sizeof(mileage[0]), compare_cities);   

   printf("Size of array: %ld\n", (sizeof(mileage) / sizeof(mileage[0])));
   printf("Size of node: %ld\n", sizeof(mileage[0]));

   if (ptr != NULL)                                        //if ptr is no longer null, bsearch has found the city, the program then prints the distance
      printf("%s is %d miles from New York City.\n", city_name, ptr->miles);
   else                                                    //else the program infors the user the city wasn't found
      printf("%s wasn't found.\n", city_name); 

   return 0;
}

int compare_cities(const void *key_ptr, const void *element_ptr)
                                                           //compares the key to the current node being evaluated by bsearch.
{
   return strcmp((char *) key_ptr, ((struct city_info *) element_ptr)->city);
}
