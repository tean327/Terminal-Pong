#include"../include/Ball.h"
#include<stdlib.h>

Ball* CreateBall()
{
    Ball *ball = (Ball*)malloc(sizeof(Ball));
    if(!ball)
        return NULL;
    
    ball->posX = 20;
    ball->posY = 5;
    ball->speed = 0.0005f;
    ball->VelocityX = 1;
    ball->VelocityY = 0;

    return ball;
}

void BallProcess(Ball* b, Player* p1, Player* p2)
{
   b->posX += b->VelocityX * b->speed;
    b->posY += b->VelocityY * b->speed;

    // Walls (playable rows are 1..GRID_HEIGHT-2)
    if (b->posY <= 1 && b->VelocityY < 0) {
        b->posY = 1;
        b->VelocityY = -b->VelocityY;
    } else if (b->posY >= 12 - 2 && b->VelocityY > 0) {
        b->posY = 12 - 2;
        b->VelocityY = -b->VelocityY;
    }

    int cellX = (int)(b->posX+ 0.5f);
    int cellY = (int)(b->posY+ 0.5f);

    // Paddle P1 (column 1)
    if (cellX <= 1 && b->VelocityX < 0) {
        int diff = cellY - p1->posY;          // -1, 0, +1 if the paddle is hit
        if (diff >= -1 && diff <= 1) {
            b->posX = 2;
            b->VelocityX = 1;
            b->VelocityY = 0.5f * diff;
        }
    }
    // Paddle P2 (column GRID_WIDTH-2)
    else if (cellX >= 41 - 2 && b->VelocityX > 0) {
        int diff = cellY - p2->posY;
        if (diff >= -1 && diff <= 1) {
            b->posX = 41 - 3;
            b->VelocityX = -1;
            b->VelocityY = 0.5f * diff;
        }
    }
}