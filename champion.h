#ifndef CHAMPION_H
#define CHAMPION_H
#include<stdio.h>

typedef struct Champion
{
    int role;
    int level;
    struct Champion* next;

} Champion;

typedef enum ChampionRole
{ 
    MAGE = 1,
    FIGHTER = 2,
    SUPPORT = 3,
    TANK = 4

} ChampionRole;

Champion* createChampion();

Champion* addChampion( Champion *head, Champion *c );

Champion* buildChampionList( int n );

void printChampionList( Champion *head );

Champion* removeChampion( Champion *head );

Champion* destroyChampionList( Champion *head );


#endif