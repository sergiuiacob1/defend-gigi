#include "./arena/arena.h"

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


ArenaInfo Arena::getArenaInfo(int userId){
  int n = users.size();

  ArenaInfo res;
  res.id = id;

  int i;
  for (i = 0; i < n; ++i){
    if (Users[i].getId() == userId){
      res.playerPosition = Users[i].getPosition();
    }
    else {
      res.players.push_back(Users[i].getPosition());
    }
  }

  return res;
}

void Arena::updateUser(int userId, const std::string& move){
  int i;
  for (i = 0; i < users.size(); ++i){
    if (users[i].getId() == userId){
      users[i].update(move);
    }
  }
}
