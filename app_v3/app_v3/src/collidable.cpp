#include "./collidable.h"
#include <cmath>

inline double dist (const position&, const position&);

bool collidable::hasCollided (const collidable& object) const{
    if (dist(this->pos, object.getPosition())<=PRECISION)
        return true;
}

double dist (const position& a, const position& b){
    return sqrt ((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

inline position collidable::getPosition() const{
    return this->pos;
}