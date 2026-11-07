#include"../include/GameManager.h"
#include<stdio.h>
#include<stdlib.h>

#ifdef linux
    #include<unistd.h>
#endif

#ifdef windows
    #include<windows.h>
#endif

int main(void)
{
    Game* game = StartGame();
    if(!game)
        return 2;

    while(game->p1Score < 5 && game->p2Score < 5 && !ShouldQuit())
    {
        Manche(game);
        sleep(3);
    }

    printf("\033[HSCORE J1: %d   SCORE J2: %d\n", game->p1Score,game->p2Score);

    RemadeConsoleNormal();
    free(game);
    return 0;
}