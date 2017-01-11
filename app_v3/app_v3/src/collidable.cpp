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

bool collidable::canMove (const std::string& direction) const {
  if (direction == "left"){
    if (pos.x - DXMOV >= 0)
      return true;
  }
  else
    if (direction == "right"){
      if (pos.x + DXMOV <= CANVAS_WIDTH)
        return true;
  }
    else
      if (direction == "up"){
        if (pos.y - DXMOV >= 0)
          return true;
      }
      else
        if (direction == "down"){
          if (pos.y + DXMOV <= CANVAS_HEIGHT)
            return true;
        }


  return false;
}