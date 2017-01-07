#include "./arena.h"
#include "json.hpp"
using json = nlohmann::json;

int lastArenaId = 0;

Arena::Arena() {
  id = lastArenaId++;
  lastUpdate = now();
}

bool Arena::addUser(User user){
  if (users.size() > maxUsers)
    return false;

  users.push_back(user);
  return true;
}

bool Arena::removeUser (const std::string& userId){
  for (unsigned int i=0; i<users.size(); ++i)
    if (users[i].getId() == userId){
      users.erase (users.begin()+i);
      return true;
    }
  return false;
}

std::string Arena::getArenaInfo(const std::string& userId){
  int n = users.size();

  json res;
  res["id"] = userId;
  res["players"] = json::array();

  json auxPos;

  int i;
  for (i = 0; i < n; ++i){
    auxPos["x"] = users[i].getPosition().x;
    auxPos["y"] = users[i].getPosition().y;
    auxPos["id"] = users[i].getId();
    res["players"].push_back(auxPos);
}

  return res.dump();
}

bool Arena::updateUser(const std::string& userId, const std::string& move){
  unsigned int i;
  for (i = 0; i < users.size(); ++i){
    if (users[i].getId() == userId){
      users[i].update(move);
      return true;
    }
  }
  return false;
}