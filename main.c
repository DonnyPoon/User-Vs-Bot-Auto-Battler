#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "champion.h"

int main(int argc, char *argv[])
{
    Champion* player1;
    Champion* player2;
    Champion* newChamp;
    char player1Role[10];
    char player2Role[10];
    int roundNumber = 1;

    srand(time(NULL));

    if (atoi(argv[1]) <= 0 || !argv[1]) // validate command line argument for number of champions
    {
        printf("Incorrect number champions entered.\n");
        return 0;
    }

    player1 = buildChampionList(atoi(argv[1]));
    player2 = buildChampionList(atoi(argv[1]));

    while (player1 != NULL && player2 != NULL) // begin game loop
    {
        printf("----- ROUND %d -----\n", roundNumber);
        roundNumber = roundNumber + 1;

        printChampionList(player1);
        printChampionList(player2);

        switch (player1->role) // find role of head champion
        {
        case 1:
            strcpy(player1Role, "MAGE");
            break;
        case 2:
            strcpy(player1Role, "FIGHTER");
            break;
        case 3:
            strcpy(player1Role, "SUPPORT");
            break;
        case 4:
            strcpy(player1Role, "TANK");
            break;
        default:
            break;
        }

        switch (player2->role) // find role of head champion
        {
        case 1:
            strcpy(player2Role, "MAGE");
            break;
        case 2:
            strcpy(player2Role, "FIGHTER");
            break;
        case 3:
            strcpy(player2Role, "SUPPORT");
            break;
        case 4:
            strcpy(player2Role, "TANK");
            break;
        default:
            break;
        }
        printf("Player 1 is a %s and Player 2 is a %s\n", player1Role, player2Role);

        // find permutation based on roles to issue each result
        if (player1->role == MAGE && player2->role == MAGE) // MM
        {
            if (player1->level > player2->level)
            {
                player1 = removeChampion(player1);
                player2 = removeChampion(player2);
                newChamp = createChampion();
                player1 = addChampion(player1, newChamp);
                player2 = removeChampion(player2);
                printf("Player 1 (MAGE) wins and gains one new champion.\n");
                printf("Player 2 (MAGE) loses one champion.\n");
            }
            else if(player1->level < player2->level)
            {
                player1 = removeChampion(player1);
                player2 = removeChampion(player2);
                newChamp = createChampion();
                player2 = addChampion(player2, newChamp);
                player1 = removeChampion(player1);
                printf("Player 1 (MAGE) loses one champion.\n");
                printf("Player 2 (MAGE) wins and gains one new champion.\n");
            }
            else
            {
                player1 = removeChampion(player1);
                player2 = removeChampion(player2);
                printf("Tie, nothing happens.\n");
            } 
        }
        else if (player1->role == MAGE && player2->role == FIGHTER) // MF
        {
            if (player1->level > player2->level)
            {
                player1 = removeChampion(player1);
                player2 = removeChampion(player2);
                newChamp = createChampion();
                player1 = addChampion(player1, newChamp);
                printf("Player 1 (MAGE) wins and gains one new champion.\n");
                printf("Player 2 (FIGHTER) loses with no penalty.\n");
            }
            else if(player1->level < player2->level)
            {
                player1 = removeChampion(player1);
                player2 = removeChampion(player2);
                player1 = removeChampion(player1);
                printf("Player 1 (MAGE) loses one champion.\n");
                printf("Player 2 (FIGHTER) wins and gains no reward.\n");
            }
            else
            {
                player1 = removeChampion(player1);
                player2 = removeChampion(player2);
                printf("Tie, nothing happens.\n");
            } 
        }
        else if (player1->role == FIGHTER && player2->role == MAGE) // FM
        {
            if (player1->level > player2->level)
            {
                player1 = removeChampion(player1);
                player2 = removeChampion(player2);
                player2 = removeChampion(player2);
                printf("Player 1 (FIGHTER) wins and gains no reward.\n");
                printf("Player 2 (MAGE) loses one champion.\n");
            }
            else if(player1->level < player2->level)
            {
                player1 = removeChampion(player1);
                player2 = removeChampion(player2);
                newChamp = createChampion();
                player2 = addChampion(player2, newChamp);
                printf("Player 1 (FIGHTER) loses with no penalty.\n");
                printf("Player 2 (MAGE) wins and gains one new champion.\n");
            }
            else
            {
                player1 = removeChampion(player1);
                player2 = removeChampion(player2);
                printf("Tie, nothing happens.\n");
            } 
        }
        else if (player1->role == MAGE && player2->role == SUPPORT) // MS
        {
            if (player1->level > player2->level)
            {
                player1 = removeChampion(player1);
                player2 = removeChampion(player2);
                newChamp = createChampion();
                player1 = addChampion(player1, newChamp);
                player2 = removeChampion(player2);
                player2 = removeChampion(player2);
                printf("Player 1 (MAGE) wins and gains one new champion.\n");
                printf("Player 2 (SUPPORT) loses two champions.\n");
            }
            else if(player1->level < player2->level)
            {
                player1 = removeChampion(player1);
                player2 = removeChampion(player2);
                newChamp = createChampion();
                player2 = addChampion(player2, newChamp);
                newChamp = createChampion();
                player2 = addChampion(player2, newChamp);
                player1 = removeChampion(player1);
                printf("Player 1 (MAGE) loses one champion.\n");
                printf("Player 2 (SUPPORT) wins and gains no reward.\n");
            }
            else
            {
                player1 = removeChampion(player1);
                player2 = removeChampion(player2);
                printf("Tie, nothing happens.\n");
            } 
        }
        else if (player1->role == SUPPORT && player2->role == MAGE) // SM
        {
            if (player1->level > player2->level)
            {
                player1 = removeChampion(player1);
                player2 = removeChampion(player2);
                newChamp = createChampion();
                player1 = addChampion(player1, newChamp);
                newChamp = createChampion();
                player1 = addChampion(player1, newChamp);
                player2 = removeChampion(player2);
                printf("Player 1 (SUPPORT) wins and gains no reward.\n");
                printf("Player 2 (MAGE) loses one champion.\n");
            }
            else if(player1->level < player2->level)
            {
                player1 = removeChampion(player1);
                player2 = removeChampion(player2);
                newChamp = createChampion();
                player2 = addChampion(player2, newChamp);
                player1 = removeChampion(player1);
                player1 = removeChampion(player1);
                printf("Player 1 (SUPPORT) loses two champions.\n");
                printf("Player 2 (MAGE) wins and gains one new champion.\n");
            }
            else
            {
                player1 = removeChampion(player1);
                player2 = removeChampion(player2);
                printf("Tie, nothing happens.\n");
            } 
        }
        else if (player1->role == MAGE && player2->role == TANK) // MT
        {
            player1 = removeChampion(player1);
            player2 = removeChampion(player2);
            player2 = removeChampion(player2);
            newChamp = createChampion();
            player1 = addChampion(player1, newChamp);
            printf("Player 1 (MAGE) wins and gains one new champion.\n");
            printf("Player 2 (TANK) loses one champion.\n");
        }
        else if (player1->role == TANK && player2->role == MAGE) // TM
        {
            player1 = removeChampion(player1);
            player2 = removeChampion(player2);
            player1 = removeChampion(player1);
            newChamp = createChampion();
            player2 = addChampion(player2, newChamp);
            printf("Player 1 (TANK) loses one champion.\n");
            printf("Player 2 (MAGE) wins and gains one new champion.\n");
        }
        else if (player1->role == FIGHTER && player2->role == FIGHTER) // FF
        {
            player1 = removeChampion(player1);
            player2 = removeChampion(player2);
            newChamp = createChampion();
            player1 = addChampion(player1, newChamp);
            newChamp = createChampion();
            player2 = addChampion(player2, newChamp);
            printf("Player 1 (FIGHTER) gains one new champion.\n");
            printf("Player 2 (FIGHTER) gains one new champion.\n");
        }
        else if (player1->role == FIGHTER && player2->role == SUPPORT) // FS
        {
            if (player1->level > player2->level)
            {
                player1 = removeChampion(player1);
                player2 = removeChampion(player2);
                player2 = removeChampion(player2);
                printf("Player 1 (FIGHTER) wins and gains no reward.\n");
                printf("Player 2 (SUPPORT) loses one champion.\n");
            }
            else if(player1->level < player2->level)
            {
                player1 = removeChampion(player1);
                player2 = removeChampion(player2);
                newChamp = createChampion();
                player2 = addChampion(player2, newChamp);
                printf("Player 1 (FIGHTER) loses with no penalty.\n");
                printf("Player 2 (SUPPORT) wins and gains one new champion.\n");
            }
            else
            {
                player1 = removeChampion(player1);
                player2 = removeChampion(player2);
                printf("Tie, nothing happens.\n");
            }
        }
        else if (player1->role == SUPPORT && player2->role == FIGHTER) // SF
        {
            if (player1->level > player2->level)
            {
                player1 = removeChampion(player1);
                player2 = removeChampion(player2);
                newChamp = createChampion();
                player1 = addChampion(player1, newChamp);
                printf("Player 1 (SUPPORT) wins and gains one new champion.\n");
                printf("Player 2 (FIGHTER) loses with no penalty.\n");
            }
            else if(player1->level < player2->level)
            {
                player1 = removeChampion(player1);
                player2 = removeChampion(player2);
                player1 = removeChampion(player1);
                printf("Player 1 (SUPPORT) loses one champion.\n");
                printf("Player 2 (FIGHTER) wins and gains no reward.\n");
            }
            else
            {
                player1 = removeChampion(player1);
                player2 = removeChampion(player2);
                printf("Tie, nothing happens.\n");
            } 
        }
        else if (player1->role == FIGHTER && player2->role == TANK) // FT
        {
            player1 = removeChampion(player1);
            player2 = removeChampion(player2);
            newChamp = createChampion();
            player1 = addChampion(player1, newChamp);
            printf("Player 1 (FIGHTER) wins and gains a new champion.\n");
            printf("Player 2 (TANK) loses with no penalty.\n");
        }
        else if (player1->role == TANK && player2->role == FIGHTER) // TF
        {
            player1 = removeChampion(player1);
            player2 = removeChampion(player2);
            newChamp = createChampion();
            player2 = addChampion(player2, newChamp);
            printf("Player 1 (TANK) loses with no penalty.\n");
            printf("Player 2 (FIGHTER) wins and gains a new champion.\n");
        }
        else if (player1->role == SUPPORT && player2->role == SUPPORT) // SS
        {
            player1 = removeChampion(player1);
            player2 = removeChampion(player2);
            player1 = removeChampion(player1);
            player2 = removeChampion(player2);
            printf("Player 1 (SUPPORT) loses one champion.\n");
            printf("Player 2 (SUPPORT) loses one champion.\n");
        }
        else if (player1->role == SUPPORT && player2->role == TANK) // ST
        {
            player1 = removeChampion(player1);
            player2 = removeChampion(player2);
            newChamp = createChampion();
            player2 = addChampion(player2, newChamp);
            printf("Player 1 (SUPPORT) loses with no penalty.\n");
            printf("Player 2 (TANK) wins and gets a new champion.\n");
        }
        else if (player1->role == TANK && player2->role == SUPPORT) // TS
        {
            player1 = removeChampion(player1);
            player2 = removeChampion(player2);
            newChamp = createChampion();
            player1 = addChampion(player1, newChamp);
            printf("Player 1 (TANK) wins and gets a new champion.\n");
            printf("Player 2 (SUPPORT) loses with no penalty.\n");
        }

        else if (player1->role == TANK && player2->role == TANK) // TT
        {
            player1 = removeChampion(player1);
            player2 = removeChampion(player2);
            printf("Tie, nothing happens.\n");
        }
    }

    if (player1 == NULL && player2 == NULL)
    {
        printf("Player 1 ending champion list:");
        printChampionList(player1);
        printf("Player 2 ending champion list:");
        printChampionList(player2);
        printf("TIE -- both players ran out of champions.\n");
    }
    if (player1 == NULL && player2 != NULL)
    {
        printf("Player 1 ending champion list:");
        printChampionList(player1);
        printf("Player 2 ending champion list:");
        printChampionList(player2);
        printf("Player 1 ran out of champions. Player 2 wins.\n");
    }
    if (player1 != NULL && player2 == NULL)
    {
        printf("Player 1 ending champion list:");
        printChampionList(player1);
        printf("Player 2 ending champion list:");
        printChampionList(player2);
        printf("Player 2 ran out of champions. Player 1 wins.\n");
    }
    player1 = destroyChampionList(player1);
    player2 = destroyChampionList(player2);
    free(newChamp);

    
    return 0;
}
