#ifndef GRID_MANAGER_H
#define GRID_MANAGER_H

#include"../include/Players.h"
#include"../include/Ball.h"
#include"../include/console.h"

#define GRID_WIDTH 41
#define GRID_HEIGHT 12

#define KEY_UP      0x0105
#define KEY_DOWN    0x0106

char* GenerateGridStr();
int ChangeGrid(Player* p1, Player* p2, Ball* b);

#endif