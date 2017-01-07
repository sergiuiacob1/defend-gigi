#ifndef BALL_H
#define BALL_H
#include "./collidable.h"

class ball:public collidable {
    int id;
    public:
    int getId() const {return id;}
    ball();
    void setId(const int& newId) {id=newId;}
};

#endif