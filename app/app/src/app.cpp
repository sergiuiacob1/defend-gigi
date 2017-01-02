// This file generated by ngrestcg
// For more information, please visit: https://github.com/loentar/ngrest

#include "./app.h"

std::string app::echo(const std::string& text)
{
    return "Hi, " + text;
}

std::string app::hello(const std::string& name){
  return "Buna si tie" + name;
}

ArenaInfo app::getArenaInfo(const std::string& id, const std::string& userId){
  int i;
  for (i = 0; i < arenas.size(); ++i){
    if (arenas[i].getId() == id)
      return arenas[i].getArenaInfo(userId);
  }
  ArenaInfo res;
  return res;
}

GameInfo app::startGame(std::string name){
  int i;
  User user(name, {0, 0});
  for (i = 0; i < arenas.size(); ++i){
    if (arenas[i].addUser(user)){
      return {user.getId(), arenas[i].getId()};
    }
  }
  //no arenas left for the user
  //create a new arena

  Arena arena();
  arenas.push_back(arena);
  arenas[arenas.size() - 1].addUser(user);
  return {user.getId(), arenas[arenas.size() - 1].getId()};
}

std::string app::updateArenaInfo(const std::string& arenaId, const std::string& userId, const std::string& move){
  int i;
  for (i = 0; i < arenas.size(); ++i){
    if (arenas[i].getId() == arenaId){
      arenas[i].updateUser(userId, move);
    }
  }
  return "Okay";
}
