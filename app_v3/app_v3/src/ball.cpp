#include "./ball.h"

ball::ball(int x, int y, int xDest, int yDest) : movement(x, y, xDest, yDest, 900){
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
