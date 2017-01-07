#include "./collidable.h"

inline double dist (const position&, const position&);

bool collidable::hasCollided (const collidable& object) const{
    int temp;
    temp=dist(this->pos, object.getPosition());
    if (temp<=PRECISION*PRECISION)
        return true;
    return false;
}

double dist (const position& a, const position& b){
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

