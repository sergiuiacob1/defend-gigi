#include "./ball.h"

ball::ball(int x, int y, int xDest, int yDest) : movement(x, y, xDest, yDest, 1500){
    lastUserToHitTheBall = -1;
    //movement = Movement(x, y, xDest, yDest, 50);
}

int ball::getX(){
  return movement.getX();
}

int ball::getY(){
  return movement.getY();
}

void ball::update(){
  onUpdate();
}

void ball::onUpdate(){
  movement.update();
}

bool ball::isOutsideMap(){
  if (getX() > 1920 || getX() < 0 ||
      getY() > 1920 || getY() < 0)
    return true;
  return false;
}
