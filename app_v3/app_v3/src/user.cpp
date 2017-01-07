#include "./user.h"

int lastUserId = 0;

User::User(const std::string& name, const position& pos){
  this->name = name;
  this->pos = pos;

  this->id = lastUserId++;

  lastUpdate = now();
}

void User::update(const std::string& move){
  onUpdate(move);
  lastUpdate = now();
}

void User::onUpdate(const std::string& move){
  if (move == "left") {
    pos.x -= 5;
  }
  else if (move == "right"){
    pos.x += 5;
  }
  else if (move == "up"){
    pos.y -= 5;
  }
  else if (move == "down"){
    pos.y += 5;
  }
}
