#ifndef COLLIDABLE_H
#define COLLIDABLE_H
#define PRECISION 50
#include "./utils.h"

class collidable{
    position pos;
    double speed, angle;
    int id;
    int movX, movY;
    
    public:
    inline position getPosition() const {return pos;}
    double getSpeed() const {return speed;}
    int getId() const {return id;}
    int getMovX() const {return movX;}
    int getMovY() const {return movY;}
    
    void setId(const int& newId) {id=newId;}
    void setAngle (const double& newAngle) {angle=newAngle;}
    void setSpeed (const double& newSpeed) {speed=newSpeed;}
    void setPosition (const position& newPos) {pos=newPos;}
    void setMovX (const int& newMovX) {movX = newMovX;}
    void setMovY (const int& newMovY) {movY = newMovY;}

    bool hasCollided (const collidable&) const;
    bool canMove (const std::string&) const;
    bool isOutsideMap () const;
};

#endif
