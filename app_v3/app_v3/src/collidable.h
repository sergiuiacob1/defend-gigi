#ifndef COLLIDABLE_H
#define COLLIDABLE_H
#define PRECISION 10
#include "./utils.h"

class collidable{
    position pos;
    double speed, angle;
    int id;
    
    public:
    inline position getPosition() const {return pos;}
    double getSpeed() const {return speed;}
    int getId() const {return id;}
    
    void setId(const int& newId) {id=newId;}
    void setAngle (const double& newAngle) {angle=newAngle;}
    void setSpeed (const double& newSpeed) {speed=newSpeed;}
    void setPosition (const position& newPos) {pos=newPos;}

    bool hasCollided (const collidable&) const;
};

#endif