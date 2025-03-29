/*
AUTHOR: Fox Murray
DESCRIPTION: Coding Game for Praxis-Programming Class.
INPUT:
OUTPUT:
*/


// im going to explode

#include <stdio.h>
#include <string.h>

void plains();
void stats();

char playername[13];  // Reserve space for 11 characters + null terminator, storing player name
char contYN[2]; //2 letters for 1 letter 1 null terminator, confirming name, used merely as a check to continue with the enterd playername
int lvl = 1;
float playerhealth = 100; //set player's health to 100!

int main()
{
  while (1)
 {
     printf("········································································\n");
     printf(":########  #######  ##     ##     ######      ###    ##     ## ########:\n");
     printf(":##       ##     ##  ##   ##     ##    ##    ## ##   ###   ### ##      :\n");
     printf(":##       ##     ##   ## ##      ##         ##   ##  #### #### ##      :\n");
     printf(":######   ##     ##    ###       ##   #### ##     ## ## ### ## ######  :\n");
     printf(":##       ##     ##   ## ##      ##    ##  ######### ##     ## ##      :\n");
     printf(":##       ##     ##  ##   ##     ##    ##  ##     ## ##     ## ##      :\n");
     printf(":##        #######  ##     ##     ######   ##     ## ##     ## ########:\n");
     printf("········································································\n");

     printf("\nEnter your name, adventurer! \n"); 
     // Use %13s to limit input length and avoid buffer overflow
      scanf("%13s", &playername);

     printf("Ah, so your name is %s\n", playername);


     printf("Are you happy with the name, %s ?\n Y / N\n", playername);  //asks the question
     scanf("%1s", &contYN); //reads 1 character and sets the continue question to that letter. only 1 letter stops overfow

     if (strcmp(contYN,"Y") == 0 || (strcmp(contYN,"y") == 0) ) { 
        // || splits options it accepts, allowing Y and y respectively
        printf("Very well, %s \n", playername);
        break; //exits the loop
     } else if (strcmp(contYN,"N") == 0 || (strcmp(contYN,"n") == 0) ) {
        continue; //if not happy with name, shortcut to start of loop.
     } else {
        printf("\n");
     };
 }

 printf("Let the journey begin...\n");

 printf("===============================================================================\n");

 

 printf("- - - - - - - - - -\n");
 stats();
 plains();
// may need system here that checks for a given number from last called function to then run the next selected. So go back to main then out to another function rather than
// go from function to function.

 return 0;
}


void plains() // crossroads
 {
 printf("\nThe grass dances beneath your boots as you walk out onto the plains. You look around to see if theres anything to do. Off to your side you see a group of plants you recognise as potentially useful.\n There is a small, sheltered area not far off in the distance, it seems safe and secluded, it could make for a good resting place \n You find yourself standing on a path that follows through a clearing of trees, potentially to a town not far from here.\n");
 printf("- - - - - - - - - -\n");
 printf("Action:\n");
 printf("1. Harvest\n");
 printf("2. Rest\n");
 printf("3. Stats\n");
 printf("4. Move\n"); 
 // put in loop here like the name confirmation loop to check for numbers 1,2,3,4 to then call a stat function, call a heal function, call the stats function or call a different function.
}

void stats()
 {
    printf("[Name: %s]\n",playername);
 printf("[Level: %d]\n",lvl);
 printf("[Health: %.0f]\n",playerhealth); //%.0f tells the code to output %f (playerhealth) to 0 decimal places.
 printf("\n");
 }
