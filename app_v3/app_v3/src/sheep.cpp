#include "./sheep.h"
#define DXMOV 5

void Sheep::move (const std::string& direction){
    position pos = this->getPosition();

    if (direction == "left") {
    pos.x -= DXMOV * this->getSpeed();
  }
  else if (direction == "right"){
    pos.x += DXMOV * this->getSpeed();
  }
  else if (direction == "up"){
    pos.y -= DXMOV * this->getSpeed();
  }
  else if (direction == "down"){
    pos.y += DXMOV * this->getSpeed();
  }

  this->setPosition (pos);
}