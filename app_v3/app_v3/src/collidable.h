#ifndef COLLIDABLE_H
#define COLLIDABLE_H
#define PRECISION 10
#include "./utils.h"

class collidable{
    position pos;
    public:
    inline position getPosition() const;
    bool hasCollided (const collidable&) const;
};

#endif