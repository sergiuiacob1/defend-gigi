#ifndef GIGI_H
#define GIGI_H
#include "./collidable.h"

class Gigi:public collidable {
    unsigned int hp;
    public:
    Gigi() {hp=100;}
    void gotHit() {hp-=10;}
    bool isDead() const {return hp<=0;}
};

#endif