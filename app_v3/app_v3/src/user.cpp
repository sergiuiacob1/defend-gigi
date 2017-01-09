#include "./user.h"
#define DXMOV 5

User::User(const std::string& name, const std::string& id, const position& pos){
  this->name = name;
  this->pos = pos;
  this->id = id;

  this->setSheepPosition (pos);
  this->setGigiPosition (pos);

  lastUpdate = now();
}

void User::update(const std::string& move){
  onUpdate(move);
  lastUpdate = now();
}
 
void User::onUpdate(const std::string& move){
  sheep.move (move);
  if (move == "left") {
    pos.x -= DXMOV;
  }
  else if (move == "right"){
    pos.x += DXMOV;
  }
  else if (move == "up"){
    pos.y -= DXMOV;
  }
  else if (move == "down"){
    pos.y += DXMOV;
  }

  sheep.setPosition(pos);
  gigi.setPosition(pos);
}
