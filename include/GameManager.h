#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include"../include/GridManager.h"

typedef struct {
    int CurrentManche;
    int p1Score;
    int p2Score;
} Game;

Game* StartGame();
void Manche(Game* game);
#endif