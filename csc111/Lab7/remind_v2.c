/* Lab7: remind.c
   Programmer: Andrew Stake & David G
   Class: CS2
   Professor: Dr. Lee
   File Created: March 2, 2017
   File Updated: March 2, 2017
*/

/* Prints a one-month reminder list */

#include<stdio.h>
#include<string.h>

#define MAX_REMIND 50                         //creates constants for program
#define MSG_LEN 60

int read_line(char str[], int n);

int main()
{
   char reminders[MAX_REMIND][MSG_LEN + 3];   //variables for program
   char day_str[3], msg_str[MSG_LEN + 1];
   int day, i, j, num_remind = 0;

   for(;;)
   {
      if (num_remind == MAX_REMIND)           //ends if max amount of reminders is reached
      {
         printf("-- No space left --\n");
         break;
      }

      printf("Enter day and reminder: ");     //promts for and reads day
      scanf("%2d", &day);
      if (day == 0)                           //terminates if 0 is entered
         break;
      sprintf(day_str, "%2d", day);
      read_line(msg_str, MSG_LEN);            //reads in the reminder
   
      for (i = 0; i < num_remind; i++)        //organizes list to be in numerical order
         if (strcmp(day_str, reminders[i]) < 0)
            break;
      for (j = num_remind; j > i; j--)
         strncpy(reminders[j], reminders[j-1], sizeof(reminders[i]) - strlen(reminders[i]) - 1);

      strncpy(reminders[i], day_str, sizeof(reminders[i]) - strlen(reminders[i]) - i);          //creates final string
      strncat(reminders[i], msg_str, sizeof(reminders[i]) - strlen(reminders[i]) - 1);

      num_remind++;
   }

   printf("\nDay Reminder\n");                //prints all reminders
   for (i = 0; i < num_remind; i++)
      printf(" %s\n", reminders[i]);
   
   return 0;
}

int read_line(char str[], int n)              //reads all values after date into a string
{
   int ch, i = 0;

   while ((ch = getchar()) != '\n') 
      if (i < n)
         str[i++] = ch;
   str[i] = '\0';
   return i;
}
