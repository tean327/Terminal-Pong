#include"../include/GameManager.h"
#include<stdlib.h>
#include<stdio.h>

Game* StartGame()
{
    Game* game = (Game*)malloc(sizeof(Game));
    if(!game)
        return NULL;

    game->CurrentManche = 0;
    game->p1Score = 0;
    game->p2Score = 0;

    return game;
}

void Manche(Game* game)
{
    Player* p1 = CreatePlayer(6, game->p1Score);
    if(!p1)
        exit(1);

    Player* p2 = CreatePlayer(6, game->p2Score);
    if(!p2)
        exit(1);

    Ball* b = CreateBall();
    if(!b)
        exit(1);


    PrepareConsole();
    while(ChangeGrid(p1, p2, b) != 1)
    {
        RemadeConsoleNormal();
        char* str = GenerateGridStr();
        if(str)
        {

            printf("\033[HSCORE J1: %d   SCORE J2: %d\n", game->p1Score,game->p2Score);
            printf("%s\n", str);   // go to top-left, then print
            fflush(stdout);
            free(str);   
        }
        PrepareConsole();
    }

    game->p1Score = p1->score;
    game->p2Score = p2->score;

    free(p1);
    free(p2);
    free(b);
}