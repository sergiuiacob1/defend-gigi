// This file generated by ngrestcg
// For more information, please visit: https://github.com/loentar/ngrest

#include "./app_v3.h"
#include "json.hpp"
#include "./utils.h"
#include "./user.h"
#include "./arena.h"
#include "./ball.h"
#include <cstdlib>
#define DXLOOP 100
#define DXADDBALLS 5000

using json = nlohmann::json;

std::vector <Arena> arenas;
unsigned long long int lastLoopUpdate;

int addUserToArena (const std::string&, const std::string&);
void addBallsToArena (const int&, const int&);
void updateArena (const std::string&);
void gameLoop();

std::string app::hello(const std::string& name){
  log(name);
  return "Buna si tie" + name;
}

std::string app::getArenaInfo(const std::string& id, const std::string& userId){
  updateArena(id);

  //int intId = std::stoi(id);
  //int intUserId = std::stoi(userId);
  for (unsigned int i = 0; i < arenas.size(); ++i){
   //if (arenas[i].getId() == intId)
      return arenas[i].getArenaInfo(userId);
  }
  json res;
  res["output"] = "okay";
  return res.dump();
}

std::string app::startGame(const std::string& name, const std::string& id){
  json res;
  int arenaId;
  arenaId = addUserToArena (name, id);
  //addBallsToArena (arenaId, 2);

  res["userId"] = id;
  res["arenaId"] = arenaId;
  return res.dump();
}

Stack arenasWithNrOfPlayers[maxUsers+5];

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
  	if (!arenasWithNrOfPlayers[i].isEmpty())
  		break;

  if (i!=10){
  	int tempArenaId=arenasWithNrOfPlayers[i].popStack();
  	arenas[tempArenaId].addUser(user);
    arenasWithNrOfPlayers[arenas[tempArenaId].getNrUsers()].pushStack (tempArenaId);
  	res["userId"] = user.getId();
    res["arenaId"] = tempArenaId;
    return res.dump();
    }

  //no arenas left for the user
  //create a new arena
  Arena arena;
  arenas.push_back(arena);
  arenas[arenas.size() - 1].addUser(user);
  arenasWithNrOfPlayers[arenas[1].pushStack (arenas[arenas.size()-1].getId());

  res["userId"] = user.getId();
  res["arenaId"] = arenas[arenas.size() - 1].getId();
  return res.dump();*/
}

void addBallsToArena (const int &arenaId, const int &nrOfBalls){
  position init;
  ball newBall;

  for (int i=0; i<nrOfBalls; ++i){
      init.x = rand() % CANVAS_WIDTH;
      init.y = rand() % CANVAS_HEIGHT;
      newBall.setPosition (init);
      newBall.setId(arenas[arenaId].getTotalNrOfBalls() + 1);
      arenas[arenaId].addBall (newBall);
  }
}

std::string app::endGame(const std::string& id){
  json res;
  if (arenas[0].removeUser (id))
    res["output"] = "Okay";
  res["output"] = "Not okay";
  return res.dump();
}

std::string app::updateArenaInfo(const std::string& arenaId, const std::string& userId, const std::string& move){
  json res;
  int intArenaId = std::stoi(arenaId);
  //int intUserId = std::stoi(userId);
  for (unsigned int i = 0; i < arenas.size(); ++i){
    if (arenas[i].getId() == intArenaId){
      if (arenas[i].updateUser(userId, move)){
        res["output"] = "Okay";
        return res.dump();
      }
    }
  }
  res["output"] = "not okay";
  return res.dump();
}

void updateArena (const std::string& arenaId){
  if (now() - lastLoopUpdate >= DXLOOP){
    lastLoopUpdate = now();
    gameLoop();
  }

  //if (now() - lastAddedBalls ())

  if (!arenas.size())
    return;

  for (unsigned int i = 0; i<arenas.size(); ++i){
    arenas[i].processCollisions();
    //moveBalls();
  }
  return;
}

void gameLoop(){

}

std::string app::fire(const std::string& arenaId, const std::string& userId, const std::string& x, const std::string& y){
  json res;

  int tempX=std::stoi(x);
  int tempY=std::stoi(y);
  arenas[0].addBall (tempX, tempY);

  res["output"]="okay";
  return res.dump();
}