/*
AUTHOR: Fox Murray
DESCRIPTION: Coding Game for Praxis-Programming Class.
INPUT:
OUTPUT:
*/


#include <stdio.h> // 
#include <time.h> //used for random number generation
#include <stdlib.h> //used for random number generation
#include <string.h> //allows the system to read and recognise strings instead of just characters.

void plains();
void move();
void dungeon();
void stats();
void healaction();
void inventorycheck();
void explore();
void fight();
void levelup();

char playername[13];  // Reserve space for 11 characters + null terminator, storing player name
char contYN[2]; //2 letters for 1 letter 1 null terminator, confirming name, used merely as a check to continue with the enterd playername
int lvl = 1; // set's player level to 1
int playerhealth = 100; //set player's health to 100!
int healnumber = 10; //used for incremental heal through resting.
int healthcap = 100; //unused for now, use for level up!
char choiceinput[20]; //Reserve space of 1 character + null terminator. Variable updated to reflect player's choice so the code can choose the correct branch to execute
int hasHarvested = 0; //used to check if herbs can be harvested.
int inventory_herb = 0; //how many herbs in inventory.
int inventory_potion = 0;  // how many potions you have in your inventory.
int dungeonfloor = 1; //the progress in the dungeon
int enemyident = 0; //unused, but allows multiple enemy functionality!
int enemyhealth = 100; //enemy health counter
int incomingdamage = 0; //used for calcualting damage dealt to the player
int damage = 0; //used for damage dealt to an enemy
int lvlticker = 0; //used to count the progress to a level up.

int main()
{
   srand(time(NULL)); //generates random numbers. needed to be called once.
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

     printf("\nEnter your name, adventurer! (no spaces!)\n"); 
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


void plains() // Location 1
{
   printf("\nThe grass dances beneath your boots as you walk out onto the plains. You see a village in the distance and a Dungeon nearby.\n");
   hasHarvested = 0;
   while(1)
   {
      printf("- - - - - P L A I N S - - - - -\n");
      printf("Please type the action you'd like to do.\n");
      printf("- harvest\n");
      printf("- rest\n");
      printf("- stats\n");
      printf("- move\n"); 
      printf("- inventory\n");
      printf("- - - - - - - - - - - - - - - -\n");

      // Read user input
      scanf("%19s", &choiceinput);
      
      // Handle different player actions
      if (strcmp(choiceinput,"harvest") == 0 ) {
         printf("You walk over to a prominent patch of grass and start to root through it.\n");
         if (hasHarvested == 0) {
            printf("You find some interesting Herbs.\n");
            hasHarvested = 1;
            inventory_herb += 1; // Add 1
         } else {
            printf("You find nothing...\n");
         }
      } else if (strcmp(choiceinput,"rest") == 0 ) {
         printf("You walk over to the sheltered area, stepping into a cave and lying down. You fall asleep and wake up feeling more refreshed than before.\n");
         healaction(); // Heal the player
      } else if (strcmp(choiceinput,"stats") == 0) {
         stats(); // Show stats
      } else if (strcmp(choiceinput,"move") == 0) {
         printf("Moving on...\n");
         break; // Exit the loop and move on
      } else if (strcmp(choiceinput, "inventory") == 0) {
         inventorycheck(); // Show inventory
      }
   }
   // After breaking the loop, continue the game (e.g., go to dungeon or other locations)
   move(); // Call the move function
}

void move() {
   printf("- - - - -Move to where?- - - - -\n");
   printf("- plains\n");
   printf("- dungeon\n");
   printf("- end (closes the game)\n");
   printf("- - - - - - - - - - - - - - - - -\n");

   scanf("%19s", choiceinput);  // Use choiceinput (no need for &)

   if (strcmp(choiceinput, "plains") == 0) {
       plains();
   } else if (strcmp(choiceinput, "dungeon") == 0) {
     dungeonfloor = 1;
       dungeon();
   } else if (strcmp(choiceinput, "end") == 0) {

   } else if (strcmp(choiceinput, "locked") == 0) {
       printf("You cannot access this location yet...");
   }
}

void dungeon() // Location 2
{
    
  printf("\nThe air is damp, moss clings to the stone bricks in the walls and you feel a sense of unease as you descend the steps...\n");

   while(1)
   {
      printf("- - - - - D U N G E O N - - - - -\n");
      printf("Please type the action you'd like to do.\n");
      printf("- explore\n");
      printf("- rest\n");
      printf("- stats\n");
      printf("- move\n"); 
      printf("- inventory\n");
      printf("- - - - - - - - - - - - - - - - -\n");

      // Read user input
      scanf("%19s", &choiceinput);
      
     
      if (strcmp(choiceinput,"explore") == 0 ) {
        //make a dungeon fight / explore UI. shows floor that gets bigger each time, then roll rng to see if theres a fight. then go to fight()
		 explore();
        
      } else if (strcmp(choiceinput,"rest") == 0 ) {
         printf("There's nowhere to rest...\n");
      } else if (strcmp(choiceinput,"stats") == 0) {
         stats(); // Show stats
      } else if (strcmp(choiceinput,"move") == 0) {
         printf("You begin climbing back up the cold steps...\n");
         break; // Exit the loop and move on
      } else if (strcmp(choiceinput, "inventory") == 0) {
         inventorycheck(); // Show inventory
      }
   }
   // After breaking the loop, continue the game (e.g., go to dungeon or other locations)
   move(); // Call the move function
}

void stats()
{
    printf("\n");
    printf("[Name: %s]\n",playername);
 printf("[Level: %d]\n",lvl);
 printf("[Health: %d/%d]\n",playerhealth,healthcap); //%.0f tells the code to output %f (playerhealth) to 0 decimal places.
 printf("\n");
}

void healaction()
{
  
   playerhealth = playerhealth + healnumber;
   if (playerhealth > 100){
   playerhealth = 100;
   printf("You cannot heal further!\n");
   printf("Your health is now %.0f\n",playerhealth);
}
  else printf("Your health is now %.0f\n",playerhealth);
}

void inventorycheck()
{
   printf("You have %i Herbs\n", inventory_herb);
   printf("You have %i Potions\n", inventory_potion);
}

void explore()
{
 printf("You step down into the dungeon. . .\n");
 enemyhealth = 100;
  while(1)
  {
    printf("\n");
    enemyident = 3;
    printf("Dungeon - Floor %d\n",dungeonfloor);
    printf("A zombie blocks the way!\n");
    printf("- - - - - FIGHT - - - - -\n");
    printf("attack\n");
    printf("heal\n");
    printf("stats\n");
    printf("enemy (check's enemy stats)\n");
    printf("escape\n");
    printf("- - - - - - - - - - - - -\n");

    scanf("%19s", &choiceinput);

      if (strcmp(choiceinput,"attack") == 0) { //Attack
         fight();
     } 
     else if(strcmp(choiceinput,"heal") == 0) {
      if (inventory_potion >= 1) 
         {
          printf("You used a potion!\n");
          playerhealth = playerhealth + 20;
          if (playerhealth > healthcap){
          playerhealth = healthcap; //stops overhealing
          }
          printf("Gained 20 health! [%d/%d]\n", playerhealth, healthcap);
          inventory_potion -= 1; //removes the used potion
         } 
         else 
         {
          printf("You have no potions!\n");
         }
     } 
     else if(strcmp(choiceinput,"stats") == 0) { //open stats
        stats();
     }
     else if(strcmp(choiceinput,"enemy") == 0) { // enemy stats
        if(enemyident=3)
            printf("A Zombie! Relatively weak. HP:%d",enemyhealth);

    else if(strcmp(choiceinput,"escape") == 0)
         {
            printf("you find a moment to escape...");
            break;
         }

  }
 }
 printf("you escape from the dungeon");
 move();
}

void fight() {
    srand(time(NULL));  // Seed the random number generator once
    // Player attack
    int damage = rand() % 11 + 10;  // Random damage between 10 and 20
    damage *= lvl;  // Multiply damage by level
    printf("%s attacks!\n", playername);
    enemyhealth -= damage;
    printf("Enemy took %d damage! Enemy's remaining health: %d\n", damage, enemyhealth);

    // Enemy attack
    int incomingdamage = rand() % 11 + 10;  // Random damage between 10 and 20
    playerhealth -= incomingdamage * 0.5;  // Subtract incoming damage from player health
    printf("Zombie attacks! Player's remaining health: %d\n\n", playerhealth);

    if (playerhealth <= 0) {
        printf("Game over!\n");
        exit(1);
        main();
    }

    else if (enemyhealth < 0)
    {
     printf("Zombie slain!\n");

     lvlticker += 1; //adds 1 to level ticker / level progress
     dungeonfloor += 1; // go deeper int othe dungeon
     if (lvlticker >= lvl)
         {
         levelup(); //if level has been completed, run level up script.
        }
     dungeon();
    }
    
   
}

void levelup()
{
int healthbump = lvl * 10; //heals the player 10 for each level completed.
healthcap = healthcap + healthbump;
playerhealth = playerhealth + 20; //heals the player a little for leveling up.
if (playerhealth > healthcap){
    playerhealth = healthcap;
}
lvlticker = 0;
hasHarvested = 0;
lvl += 1;
printf("level up! Now level %d\n",lvl);
printf("You found a health potion!\n");
printf("Health restored to max!\n");
inventory_potion += 1;
dungeon();
}

//code by fox murray 2025
