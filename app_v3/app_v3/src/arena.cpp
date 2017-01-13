#include "./arena.h"
#include "json.hpp"
#include <algorithm>
using json = nlohmann::json;

int Arena::totalNrOfBalls = 0;
int lastArenaId = 0;

bool cmp (const User& a, const User& b){
  return a.getScore() > b.getScore();
}

Arena::Arena() {
  id = lastArenaId++;
  lastUpdate = now();
  balls.clear();
  users.clear();
}

bool Arena::addUser(User user){
  if (users.size() > maxUsers)
    return false;

  users.push_back(user);
  std::cout<<"in arena addUser "<<user.getId()<<'\n';
  return true;
}

bool Arena::removeUser (const std::string& userId){
  /*for (unsigned int i = 0; i < 2; ++i)
    balls.pop_back();*/

  for (unsigned int i=0; i<users.size(); ++i)
    if (users[i].getId() == userId){
      users.erase (users.begin()+i);
      return true;
    }
  return false;
}

std::string Arena::getArenaInfo(const std::string& userId){
  json res;
  res["id"] = userId;
  res["players"] = json::array();
  res["balls"] = json::array();
  res["scoreboard"] = json::array();

  json auxPos;

  for (int i = 0; i < users.size(); ++i){
    auxPos["x"] = users[i].getPosition().x;
    auxPos["y"] = users[i].getPosition().y;
    auxPos["id"] = users[i].getId();
    auxPos["name"] = users[i].getName();
    auxPos["score"] = users[i].getScore();
    auxPos["hp"] = users[i].getGigi().getHp();
    res["players"].push_back(auxPos);
  }

  if (users.size())
    sort (users.begin(), users.begin() + users.size(), cmp);
    
  json auxPos2;
  for (unsigned int i = 0; i < users.size() && i<5; ++i){
    auxPos2["name"] = users[i].getName();
    auxPos2["score"] = users[i].getScore();
    res["scoreboard"].push_back (auxPos2);
  }

  json auxPos3;
  for (unsigned int i = 0; i < balls.size(); ++i){
    auxPos3["x"] = balls[i].getX();
    auxPos3["y"] = balls[i].getY();
    auxPos3["id"] = balls[i].getId();
    res["balls"].push_back(auxPos3);
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

inline void addScoreToUser (const std::string&);
void Arena::processCollisions(){
  int i, j;
  bool removeThisBall;
  for (i = 0; i < balls.size(); ++i){
    removeThisBall = false;

    for (j = 0; j < users.size(); ++j)
      if (balls[i].hasCollided(users[j].getGigi())){
        if (balls[i].getLastUserToHitTheBall() == users[j].getId())
          continue;

        this->addScoreToUser (balls[i].getLastUserToHitTheBall());
        users[j].gotHit();

        if (users[j].getGigi().isDead()){
          users.erase (users.begin() + j); --j;
        }

        removeThisBall = true;
    }
    if (removeThisBall){
      this->removeBall(balls[i].getId());
      --i;
    }
  }
  return;
}

inline void Arena::addScoreToUser (const std::string& userId){
  unsigned int i;
  for (i = 0; i < users.size(); ++i)
    if (users[i].getId() == userId){
      users[i].incrementScore (10);
      return;
    }
}

bool Arena::addBall (const std::string& userId, const int& x, const int& y){
  int userIndex = -1;
  for (unsigned int i = 0; i < users.size(); ++i){
    if (userId == users[i].getId())
      userIndex = i;
  }
  if (userIndex == -1)
    return false;


  //ball
  ball newBall(users[userIndex].getPosition().x, users[userIndex].getPosition().y, x, y);
  newBall.setLastUserToHitTheBall (userId);
  //position pos;
  //pos.x = x; pos.y = y;
  //newBall.setPosition (pos);
  balls.push_back (newBall);
  return true;
}

bool Arena::removeBall(const int& id){
  for (unsigned int i = 0; i < balls.size(); ++i)
    if (balls[i].getId() == id){
      balls.erase (balls.begin() + i);
      return true;
    }
  return false;
}

void Arena::update(){
  onUpdate();
}

void Arena::onUpdate(){
  unsigned int n = balls.size();

  unsigned int i;
  for (i = 0; i < n; ++i)
    if (balls[i].isOutsideMap()){
      this->removeBall (balls[i].getId());
      --i;
      --n;
    }

  for (i = 0; i < n; ++i)
    balls[i].update();
}
