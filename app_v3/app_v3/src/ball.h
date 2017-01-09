#ifndef BALL_H
#define BALL_H
#include "./collidable.h"

class ball:public collidable {
    int lastUserToHitTheBall;
    public:
    ball();
    void ballHit (const int &userId) {lastUserToHitTheBall=userId;}
    void move (const int &dx) {position pos=this->getPosition(); pos.x+=dx; this->setPosition(pos);}
};

#endif