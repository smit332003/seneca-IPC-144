/*
*****************************************************************************
                          Workshop - #7 (P1)
Full Name  : MUDIT THAPAR
Student ID#: 146014212
Email      : mthapar6@gmail.com
Section    : NII

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MIN_PATH_LEN 10
#define Max_PATH_LEN 70
#define MULTIPLE 5
#define MAX_LIVES 10
#define MIN_LIVES 1


struct PlayerInfo 
{
    int lives;
    char symbol;
    int treasures;
    int history[Max_PATH_LEN];    
}; 

struct  GameInfo
{
    int moves;
    int path_length;
    int bombs[Max_PATH_LEN];
    int treasures[Max_PATH_LEN];
    int i;
};

void PlaceTheBombs(struct GameInfo *g){
     int i,j;
     printf("\nBOMB Placement\n");
     printf("--------------\n");
     printf("Enter the bomb positions in sets of %d where a value\n",
                     MULTIPLE);
     printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
     printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n",g->path_length);
    
    int cols=1;
    for( i=1;i<=g->path_length/MULTIPLE;i++)
    {
        printf("   Positions [%2d-%2d]: ",cols,cols+4);
          for( j=cols-1;j<=cols+3;j++)
            {
               scanf("%d",&g->bombs[j]);
            }
        cols=cols+5;
    }
    printf("BOMB placement set\n\n");
    return;
}

void PlaceTheTreasure(struct GameInfo *g){
     int i,j;
     printf("TREASURE Placement\n");
     printf("------------------\n");
     printf("Enter the treasure placements in sets of %d where a value\n",
                     MULTIPLE);
     printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
     printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n",g->path_length);
    
    int cols=1;
    for( i=1;i<=g->path_length/5;i++)
    {
        printf("   Positions [%2d-%2d]: ",cols,cols+4);
        for( j=cols-1;j<=cols+3;j++)
        {
        scanf("%d",&g->treasures[j]);
        }
        cols=cols+5;
    }
    printf("TREASURE placement set\n\n");
    
    return;
}
    

int main()
{
    struct  PlayerInfo player = {0, '\0', 0, {0}}; 
    struct  GameInfo   game   = {0, 0, {0}, {0}};  
    int i;
    
    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c",&player.symbol);
    do{
       printf("Set the number of lives: ");
       scanf("%d",&player.lives);
           if(player.lives < MIN_LIVES || player.lives > MAX_LIVES)
            {
              printf("     Must be between %d and %d!\n",MIN_LIVES,MAX_LIVES);
            }      
    }while(player.lives < MIN_LIVES || player.lives > MAX_LIVES);
    printf("Player configuration set-up is complete\n\n");
    printf("GAME Configuration\n");
    printf("------------------\n");
    do{
        printf("Set the path length (a multiple of %d between %d-%d): ",
                MULTIPLE,  MIN_PATH_LEN,Max_PATH_LEN);
        scanf("%d",&game.path_length);
            if(game.path_length < MIN_PATH_LEN || 
                game.path_length > Max_PATH_LEN ||
                game.path_length%MULTIPLE)
            {
                printf("     Must be a multiple of 5 and between 10-70!!!\n");
            }    
    }while(game.path_length < MIN_PATH_LEN || 
           game.path_length > Max_PATH_LEN ||
           game.path_length%MULTIPLE);      
    do{
        printf("Set the limit for number of moves allowed: ");
        scanf("%d",&game.moves);
            if(game.moves < player.lives ||
               game.moves > (int)(0.75*game.path_length) )
            {
                printf("    Value must be between %d and %d\n",
                        player.lives, (int)(0.75*game.path_length) );
            }   
    }while(game.moves < player.lives ||
           game.moves > (int)(0.75*game.path_length));    
    PlaceTheBombs(&game);
    PlaceTheTreasure(&game);
    printf("GAME configuration set-up is complete...\n\n");
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n",player.symbol);
    printf("   Lives      : %d\n",player.lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");
    printf("Game:\n");
    printf("   Path Length: %d\n",game.path_length);
    printf("   Bombs      : ");
    for( i=0;i<game.path_length;i++)
     {
        printf("%d",game.bombs[i]);
     }
    printf("\n");
    
    printf("   Treasure   : ");
    for( i=0;i<game.path_length;i++)
    {
        printf("%d",game.treasures[i]);
    }
    printf("\n\n");
    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");
    return 0;
}

