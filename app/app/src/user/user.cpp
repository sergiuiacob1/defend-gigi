#include "./user.h"

int lastUserId = 0;

User::User(std::string name, position pos){
  this.name = name;
  this.pos = pos;

  this.id = lastUserId++;

  lastUpdate = now();
}

void User::update(const std::string& move){
  onUpdate(misca);
  lastUpdate = now();
}

void User::onUpdate(const std::string& move){
  if (misca == "true") {
    pos.x += 5;
  }
}
