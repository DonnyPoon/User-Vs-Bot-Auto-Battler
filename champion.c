#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "champion.h"

Champion* createChampion() // create new champion node
{
    Champion* newChamp = (Champion*)malloc(sizeof(Champion));

    newChamp->role = rand() % 4 + 1;
    
    switch (newChamp->role)
    {
    case MAGE:
        newChamp->level = rand() % 4 + 5;
        break;
    case FIGHTER:
        newChamp->level = rand() % 4 + 1;
        break;
    case SUPPORT:
        newChamp->level = rand() % 4 + 3;
        break;
    case TANK:
        newChamp->level = rand() % 8 + 1;
        break;
    default:
        break;
    }
    newChamp->next = NULL;

    return newChamp;
}

Champion* addChampion( Champion *head, Champion *c ) // link champion node to linked list in descending champion level order
{
    Champion* headPointer = head;
    Champion* prev = NULL;
    if(head == NULL) // when adding a champion where only 1 is left on a list
    {
        return c;
    }

    while (head != NULL)
    {
        if (head->level < c->level)
        {
            if(prev == NULL) // if head is lower than the new champion level, new node is the head
            {
                c->next = head;
                return c;
            }

            prev->next = c;
            c->next = head;
            return headPointer;
        }
        prev = head;
        head = head->next;
    }
    prev->next = c;

    return headPointer;
    
}

Champion* buildChampionList( int n ) // creates and links the number of champions inputted
{
    Champion* head = createChampion();
    Champion* newChamp;

    if (n > 1)
    {
        for (int i = 0; i < n-1; i++)
        {
            newChamp = createChampion();
            head = addChampion(head, newChamp);
        }
    }

    return head;
}

void printChampionList( Champion *head ) // prints each champion node's associated role and level in linked list
{
    while (head != NULL)
    {
        switch (head->role)
        {
        case MAGE:
            printf("M%d ", head->level);
            break;
        case FIGHTER:
            printf("F%d ", head->level);
            break;
        case SUPPORT:
            printf("S%d ", head->level);
            break;
        case TANK:
            printf("T%d ", head->level);
            break;
        default:
            break;
        }

        head = head->next;
    }
    printf("\n");
}

Champion* removeChampion( Champion *head ) // remove the head of the linked list and return new head
{
    if(head == NULL) // if removing from list with one champion left
    {
        return NULL;
    }
    Champion* temp = head->next;
    free(head);

    return temp;
}

Champion* destroyChampionList( Champion *head ) // destroys the champion linked list
{
    Champion* temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return head;
}