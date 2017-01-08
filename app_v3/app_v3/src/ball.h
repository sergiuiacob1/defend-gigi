#ifndef BALL_H
#define BALL_H
#include "./collidable.h"

class ball:public collidable {
    int lastUserToHitTheBall;
    public:
    ball();
    void ballHit (const int &userId) {lastUserToHitTheBall=userId;}
};

#endif