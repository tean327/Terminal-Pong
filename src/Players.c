#include"../include/Players.h"
#include<stdlib.h>

Player* CreatePlayer(int posY, int score)
{
    Player* player = (Player*)malloc(sizeof(Player));
    if(!player)
        return NULL;

    player->posY = posY;
    player->score = score;

    return player;
}