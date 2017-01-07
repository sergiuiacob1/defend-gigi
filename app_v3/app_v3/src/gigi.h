#ifndef GIGI_H
#define GIGI_H
#include "./collidable.h"

class Gigi:public collidable {
    int id;
    unsigned int hp;
    public:
    Gigi(){hp=100;}
};

#endif