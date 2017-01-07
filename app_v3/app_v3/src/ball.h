#ifndef BALL_H
#define BALL_H
#include "./collidable.h"

class ball:public collidable {
    int id;
    double speed, angle;
    public:
    int getId(){return id;} const;
    double getSpeed() const {return speed;}
    void hitPlayer (const collidable&);
};

#endif