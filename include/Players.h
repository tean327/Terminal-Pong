#ifndef PLAYERS_H
#define PLAYERS_H

#define UP 1;
#define DOWN -1;

typedef struct {
    int posY;
    int score;
} Player;

Player* CreatePlayer(int posY, int score);


#endif