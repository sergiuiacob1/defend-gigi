#ifndef BALL_H
#define BALL_H
#include "./collidable.h"
#include "./movement.h"

class ball:public collidable {
    std::string lastUserToHitTheBall;
    Movement movement;
    void onUpdate();
    public:
    void update();
    ball(int x, int y, int xDest, int yDest);
    int getX();
    int getY();
    std::string getLastUserToHitTheBall() const {return lastUserToHitTheBall;}
    //int getLastUserToHitTheBall() const {return lastUserToHitTheBall;}

    //void setLastUserToHitTheBall (const int& userId) {lastUserToHitTheBall=userId;}
    void setLastUserToHitTheBall (const std::string& userId) {lastUserToHitTheBall = userId;}
    void move (const int &dx) {position pos=this->getPosition(); pos.x+=dx; this->setPosition(pos);}
    bool isOutsideMap();
};

#endif
