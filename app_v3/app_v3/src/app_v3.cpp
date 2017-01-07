// This file generated by ngrestcg
// For more information, please visit: https://github.com/loentar/ngrest

#include "./app_v3.h"
#include "json.hpp"
#include "./utils.h"
#include "./user.h"
#include "./arena.h"
#include "./ball.h"
#include <cstdlib>
using json = nlohmann::json;

std::vector <Arena> arenas;
std::vector <ball> balls;

int addUserToArena (const std::string&, const std::string&);
void addBalls (const int&, const int&);

std::string app::hello(const std::string& name){
  log(name);
  return "Buna si tie" + name;
}

std::string app::getArenaInfo(const std::string& id, const std::string& userId){
  int intId = std::stoi(id);
  //int intUserId = std::stoi(userId);
  for (unsigned int i = 0; i < arenas.size(); ++i){
    if (arenas[i].getId() == intId)
      return arenas[i].getArenaInfo(userId);
  }
  std::string res = "okay";
  return res;
}

std::string app::startGame(const std::string& name, const std::string& id){
  json res;
  int arenaId;
  arenaId = addUserToArena (name, id);
  addBalls (arenaId, 2);

  res["userId"] = id;
  res["arenaId"] = arenaId;
  return res.dump();
}

struct nod* arenasWithNrOfPlayers[maxUsers+5];

int addUserToArena (const std::string& name, const std::string& id){
  srand(time(NULL));

  position init;
  init.x = rand() % CANVAS_WIDTH;
  init.y = rand() % CANVAS_HEIGHT;
  User user(name, id, init);

  if (!arenas.size()){
    Arena arena;
    arenas.push_back(arena);
  }
  arenas[0].addUser(user);

  return arenas[0].getId();

  /*
  unsigned int i;
  for (i=1; i<10; ++i)
  	if (arenasWithNrOfPlayers[i])
  		break;

  if (i!=10){
  	int tempArenaId=popStack (&arenasWithNrOfPlayers[i]);
  	arenas[tempArenaId].addUser(user);
  	pushStack(&arenasWithNrOfPlayers[arenas[tempArenaId].getNrUsers()], tempArenaId);
  	res["userId"] = user.getId();
    res["arenaId"] = tempArenaId;
    return res.dump();
    }

  //no arenas left for the user
  //create a new arena
  Arena arena;
  arenas.push_back(arena);
  arenas[arenas.size() - 1].addUser(user);
  pushStack(&arenasWithNrOfPlayers[1], arenas[arenas.size()-1].getId());

  res["userId"] = user.getId();
  res["arenaId"] = arenas[arenas.size() - 1].getId();
  return res.dump();*/

}

void addBalls (const int &arenaId, const int &nrOfBalls){
  srand(time(NULL));
  position init;
  ball newBall;

  for (int i=0; i<nrOfBalls; ++i){
      init.x = rand() % CANVAS_WIDTH;
      init.y = rand() % CANVAS_HEIGHT;
      newBall.setPosition (init);
      newBall.setId(balls.size());
      balls.push_back (newBall);
  }
}

std::string app::endGame(const std::string& id){
  if (arenas[0].removeUser (id))
    return "Okay";
  return "Not okay";
}

std::string app::updateArenaInfo(const std::string& arenaId, const std::string& userId, const std::string& move){
  int intArenaId = std::stoi(arenaId);
  //int intUserId = std::stoi(userId);
  for (unsigned int i = 0; i < arenas.size(); ++i){
    if (arenas[i].getId() == intArenaId){
      if (arenas[i].updateUser(userId, move))
        return "Okay";
    }
  }
  return "Not okay";
}
