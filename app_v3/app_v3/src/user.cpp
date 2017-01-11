#include "./user.h"

User::User(const std::string& name, const std::string& id, const position& pos){
  this->name = name;
  this->pos = pos;
  this->id = id;

  this->setSheepPosition (pos);
  this->setGigiPosition (pos);

  lastUpdate = now();

  score = 0;
}

void User::update(const std::string& move){
  onUpdate(move);
  lastUpdate = now();
}
 
void User::onUpdate(const std::string& move){
  //sheep.move (move);
  if (move == "left" && this->getSheep().canMove ("left")) {
    pos.x -= DXMOV;
  }
  else if (move == "right" && this->getSheep().canMove ("right")){
    pos.x += DXMOV;
  }
  else if (move == "up" && this->getSheep().canMove ("up")){
    pos.y -= DXMOV;
  }
  else if (move == "down" && this->getSheep().canMove ("down")){
    pos.y += DXMOV;
  }

  sheep.setPosition(pos);
  gigi.setPosition(pos);
}