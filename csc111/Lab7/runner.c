/*CSC11 Computer Science 
  Lab 7 - Pointers and Arrays
  Programmer: David Gray & Andrew Stake
  Professor:  Dr.Lee 
  File Created: 3/2/2017
  File Updated: 3/2/2017
*/

#include "charlist.h"
#include <stdio.h>

/* A simple main function to play with the functionality in
   charlist.c
*/
int main()
{
	char x[10];                            //creates the char array list
	initialize_list(x);                    //intializes list
	add_to_list(x, 'c');                   //fills list with c a t
	add_to_list(x, 'a');
	add_to_list(x, 't');
	printf("Expect to see cat:  ");        //tests add_to_list
	print_list(x);

	delete_from_list(&(x[2]));             //deletes t and tests delete
	printf("Expect to see ca: ");
	print_list(x);

	int i; 
	for(i=0; i<7;i++)
	{
	 add_to_list(x, 'm' + i);
	}
	printf("Expect to see camnopqrs: ");   //tests deletion from the end of the list
	print_list(x);

	delete_from_list(&(x[4]));

	printf("Expect to see camnpqrs: ");    //tests deletion from the middle of the list
	print_list(x);

	delete_from_list(&(x[0]));
	printf("Expect to see amnpqrs: ");     //tests deletion from the end of the list
	print_list(x);

	return 0;
}
