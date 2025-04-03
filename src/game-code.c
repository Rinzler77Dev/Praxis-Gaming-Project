/*
AUTHOR: Fox Murray
DESCRIPTION: Coding Game for Praxis-Programming Class.
INPUT:
OUTPUT:
*/


// im going to explode
// add getting my freak on - sophia


#include <stdio.h> // 
#include <string.h> //allows the system to read and recognise strings instead of just characters.

void plains();
void stats();
void healaction();

char playername[13];  // Reserve space for 11 characters + null terminator, storing player name
char contYN[2]; //2 letters for 1 letter 1 null terminator, confirming name, used merely as a check to continue with the enterd playername
int lvl = 1; // set's player level to 1
float playerhealth = 90; //set player's health to 100!
float healnumber = 10;
float healthcap = 100; //unused for now, use for level up!
char travelchoiceinput[2]; //Reserve space of 1 character + null terminator. Variable updated to reflect player's choice so the code can choose the correct branch to execute


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
     // Use %13s to limit input length and avoid buffer overflow - reads the 12 letters put in in sequence. Doesnt allow for spaces though...
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
 //print the stats then call upon plains to start running that area code
 stats();
 plains();
// may need system here that checks for a given number from last called function to then run the next selected. So go back to main then out to another function rather than
// go from function to function.

 return 0;
}


void plains() // crossroads
 {
   printf("\nThe grass dances beneath your boots as you walk out onto the plains. You look around to see if theres anything to do. Off to your side you see a group of plants you recognise as potentially useful.\n There is a small, sheltered area not far off in the distance, it seems safe and secluded, it could make for a good resting place \n You find yourself standing on a path that follows through a clearing of trees, potentially to a town not far from here.\n");
   while(1)
{
 printf("- - - - - P L A I N S - - - - -\n");
 printf("Action:\n");
 printf("1. Harvest\n");
 printf("2. Rest\n");
 printf("3. Stats\n");
 printf("4. Move\n"); 
 printf("- - - - - - - - - - - - - - - -\n");

 // put in loop here like the name confirmation loop to check for numbers 1,2,3,4 to then call a stat function, call a heal function, call the stats function or call a different function.
 
   scanf("%1s",&travelchoiceinput);
   if (strcmp(travelchoiceinput,"1") == 0 ) {
      
      //action 1 selected - Harvest mechanic i dont want to add yet.
      printf("You walk over to a prominent patch of grass and start to root through it. You dont find anything. \n");
      continue; //returns to action select.

   } else if (strcmp(travelchoiceinput,"2") == 0 ) {
      
      //action 2 selected - rest (regain HP)
      printf("You walk over to the sheltered area, stepping into a cave and lying down. You fall asleep and wake up feeling more refreshed than before \n");
      healaction();
      continue;
   } else if (strcmp(travelchoiceinput,"3") == 0) {
      stats();
      continue;
   }

}

}


void stats()
{
    printf("[Name: %s]\n",playername);
 printf("[Level: %d]\n",lvl);
 printf("[Health: %.0f/%0.f]\n",playerhealth,healthcap); //%.0f tells the code to output %f (playerhealth) to 0 decimal places.
 printf("\n");
}

void healaction()
{
  
   playerhealth = playerhealth + healnumber;
   if (playerhealth > 101){
   playerhealth = 100;
   printf("You cannot heal further!\n");
   printf("Your health is now %.0f\n",playerhealth);
}
  else printf("Your health is now %.0f\n",playerhealth);
}
