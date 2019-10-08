/* Search: Prompts the user to enter a part number, then looks up the part in 
   the database.  If the part exists, prints the name and quantity on hand; if 
   not, prints an error message. */
void search(void)
{
   int i, number;

   printf("Enter part number: ");
   scanf("%d", &number);
   i=find_part(number);
   if(i>=0)
   {
      printf("Part name: %s\n", inventory[i].name);
      printf("Quantitiy on hand: %d\n", inventory[i].onhand);
   }
   else
      printf("Part not found.\n");
}

/* print: Prints a listing of all parts in the database, showing the part 
   number, part name, and qunatity on hand.  Parts are printed in the order in 
   which they were entered into the database. */

void print(void)
{
   int i;

   printf("Part Number   Part Name               Qunatity on hand\n");
   for(i=0; i<num_parts; i++)
   printf("%7d      %-25s%11d\n", inventory[i].number, inventory[i].name, 
      inventory[i].on_hand;
}
