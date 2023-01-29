/*
***************************
                          Workshop - #7 (P2)
Full Name  : Smitkumar Kalpeshkumar Patel
Student ID#: 157308214
Email      : spatel556@myseneca.ca
Section    : NCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
***************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define maxpathlength 70

#define maxlives 10

struct PlayerInfo
{
    int NLives;
    char Pname;
    int NTreasuers;
    int positions[maxpathlength];
};

struct GameInfo
{
    int N_moves;
    int N_positions;
    int bombs[maxpathlength];
    int treasure[maxpathlength];
};

int main(void)
{
    struct PlayerInfo player = { 0 };
    struct GameInfo game = { 0 };
    int flag = 0, i, j, k = 0, minmoves, maxmoves, nextmove = -1, minpathlength = 10, minlives = 1, mutiplesof = 5;
    int cnttreasure = 0;

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");

    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.Pname);


    do
    {
        flag = 0;
        printf("Set the number of lives: ");
        scanf("%d", &player.NLives);

        if (player.NLives < minlives || player.NLives > maxlives)
        {
            printf("     Must be between %d and %d!\n", minlives, maxlives);
            flag = 1;
        }
    } while (flag == 1);

    printf("Player configuration set-up is complete\n\n");

    printf("GAME Configuration\n");
    printf("------------------\n");
    do
    {
        flag = 0;
        printf("Set the path length (a multiple of %d between %d-%d): ", mutiplesof, minpathlength, maxpathlength);
        scanf("%d", &game.N_positions);
        if (game.N_positions < minpathlength || game.N_positions > maxpathlength || (game.N_positions % mutiplesof != 0))
        {

            printf("     Must be a multiple of %d and between %d-%d!!!\n", mutiplesof, minpathlength, maxpathlength);
            flag = 1;
        }

    } while (flag == 1);

    minmoves = player.NLives;

    maxmoves = (double)((game.N_positions * 0.75) + 0.5);

    do
    {
        flag = 0;
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.N_moves);
        if (game.N_moves < minmoves || game.N_moves > maxmoves)
        {
            printf("    Value must be between %d and %d\n", minmoves, maxmoves);
            flag = 1;
        }
    } while (flag == 1);

    printf("\nBOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of %d where a value\n", mutiplesof);
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.N_positions);

    for (i = 0;i < game.N_positions / mutiplesof;i++)
    {
        printf("   Positions [%2d-%2d]: ", (i * mutiplesof) + 1, (i + 1) * mutiplesof);
        for (j = 0;j < mutiplesof;j++)
        {
            scanf(" %d", &game.bombs[k++]);
        }
    }

    printf("BOMB placement set\n\n");

    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of %d where a value\n", mutiplesof);
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.N_positions);

    k = 0;

    for (i = 0;i < game.N_positions / mutiplesof;i++)
    {
        printf("   Positions [%2d-%2d]: ", (i * mutiplesof) + 1, (i + 1) * mutiplesof);
        for (j = 0;j < mutiplesof; j++)
        {
            scanf(" %d", &game.treasure[k++]);
        }
    }

    k = 0;

    printf("TREASURE placement set\n\n");

    printf("GAME configuration set-up is complete...\n\n");

    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", player.Pname);
    printf("   Lives      : %d\n", player.NLives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");

    printf("Game:\n");
    printf("   Path Length: %d\n", game.N_positions);

    printf("   Bombs      : ");
    for (i = 0;i < game.N_positions;i++)
    {
        printf("%d", game.bombs[i]);
    }
    printf("\n");

    printf("   Treasure   : ");
    for (i = 0;i < game.N_positions;i++)
    {
        printf("%d", game.treasure[i]);
    }
    printf("\n\n====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");



    do
    {
        if (nextmove > 0)
        {
            if (player.positions[nextmove - 1] == 1)
            {
                printf("===============> Dope! You've been here before!\n");
            }
            else if (game.bombs[nextmove - 1] == 1 && game.treasure[nextmove - 1] == 1)
            {
                player.positions[nextmove - 1] = 1;
                player.NLives--;
                cnttreasure++;
                game.N_moves--;
                printf("===============> [&] !!! BOOOOOM !!! [&]\n");
                printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n");
            }
            else if (game.bombs[nextmove - 1] == 1)
            {
                player.positions[nextmove - 1] = 1;
                player.NLives--;
                game.N_moves--;
                printf("===============> [!] !!! BOOOOOM !!! [!]\n");
            }
            else if (game.treasure[nextmove - 1] == 1)
            {
                player.positions[nextmove - 1] = 1;
                cnttreasure++;
                game.N_moves--;
                printf("===============> [$] $$$ Found Treasure! $$$ [$]\n");
            }
            else
            {
                player.positions[nextmove - 1] = 1;
                game.N_moves--;
                printf("===============> [.] ...Nothing found here... [.]\n");

            }

            if (game.N_moves == 0)
            {
                printf("\nNo more MOVES remaining!\n");
            }
            if (player.NLives == 0)
            {
                printf("\nNo more LIVES remaining!\n");
            }
        }
       
        
        
        if (nextmove > 0)
        {
            printf("\n  ");
            for (i = 0;i < nextmove;i++)
            {
                if (i == (nextmove - 1))
                {
                    printf("%c", player.Pname);
                }
                else
                {
                    printf(" ");
                }
            }
        }

        printf("\n  ");

        for (i = 0;i < game.N_positions;i++)
        {
            if (player.positions[i] == 0)
            {
                printf("-");
            }
            if (player.positions[i] == 1)
            {
                if (game.bombs[i] == 1 && game.treasure[i] == 1)
                {
                    printf("&");
                }
                else if (game.bombs[i] == 1 && game.treasure[i] == 0)
                {
                    printf("!");
                }
                else if (game.treasure[i] == 1 && game.bombs[i] == 0)
                {
                    printf("$");
                }
                else
                {
                    printf(".");
                }
            }
        }

        printf("\n  ");

        for (i = 0;i < game.N_positions;i++)
        {
            if ((i + 1) % 10 == 0)
            {
                printf("%d", ++k);
            }
            else
            {
                printf("|");
            }
        }

        k = 0;
        printf("\n  ");

        for (i = 0;i < game.N_positions;i++)
        {
            if ((i + 1) % 10 == 0)
            {
                printf("0");
                k = 0;
            }
            else
            {
                printf("%d", ++k);
            }
        }
        k = 0;

        printf("\n+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.NLives, cnttreasure, game.N_moves);
        printf("+---------------------------------------------------+\n");


        if (player.NLives > 0 && game.N_moves > 0)
        {
            do
            {
                flag = 0;
                printf("Next Move [1-%d]: ", game.N_positions);
                scanf("%d", &nextmove);
                if (nextmove < 1 || nextmove> game.N_positions)
                {
                    printf("  Out of Range!!!\n");
                    flag = 1;
                }
            } while (flag == 1);
            printf("\n");

        }

    } while (player.NLives > 0 && game.N_moves > 0);

    printf("\n##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n\n");

    printf("You should play again and try to beat your score!\n");

    return 0;
}