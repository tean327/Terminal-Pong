#ifndef BALL_H_
#define BALL_H_

#include"../include/Players.h"
//1 Case per frame
#define MAX_SPEED 1;

typedef struct {
    float posX;
    float posY;
    float speed;
    float VelocityX;
    float VelocityY;
} Ball;

Ball* CreateBall();
void BallProcess(Ball* b, Player* p1, Player* p2);
#endif