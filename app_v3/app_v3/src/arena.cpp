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

  json auxPos;

  for (unsigned int i = 0; i < users.size(); ++i){
    auxPos["x"] = users[i].getPosition().x;
    auxPos["y"] = users[i].getPosition().y;
    auxPos["id"] = users[i].getId();
    auxPos["name"] = users[i].getName();
    res["players"].push_back(auxPos);

    res["score"] = users[i].getScore();
    res["hp"] = users[i].getGigi().getHp();
  }

  sort (users.begin(), users.begin() + users.size(), cmp);
  for (unsigned int i = 0; i < users.size() && i<5; ++i){
    auxPos["name"] = users[i].getName();
    auxPos["score"] = users[i].getScore();
    res["scoreboard"].push_back (auxPos);
  }

  for (unsigned int i = 0; i < balls.size(); ++i){
    auxPos["x"] = balls[i].getPosition().x;
    auxPos["y"] = balls[i].getPosition().y;
    auxPos["id"] = balls[i].getId();
    res["balls"].push_back(auxPos);
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
  unsigned int i, j;
  for (i = 0; i < balls.size(); ++i)
    for (j = 0; j < users.size(); ++j)
      if (balls[i].hasCollided(users[j].getGigi())){
        balls[i].move (50);
        
        if (balls[i].getLastUserToHitTheBall() == users[j].getId())
          continue;

        users[j].gotHit();

        this->addScoreToUser (balls[i].getLastUserToHitTheBall());
        balls[i].setLastUserToHitTheBall (users[j].getId());
       	/*std::cout<<"GIGI GOT HIT  ";
        std::cout<<balls[i].getPosition().x<<" "<<balls[i].getPosition().y<<" ";
        std::cout<<users[j].getGigi().getP+osition().x<<" "<<users[j].getGigi().getPosition().y<<" ";
        std::cout<<'\n';
        std::cout<<"GIGI VIATA: "<<users[j].getGigi().getHp()<<'\n';*/
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

void Arena::addBall (const int& x, const int& y){
  ball newBall;
  position pos;
  pos.x = x; pos.y = y;
  newBall.setPosition (pos);
  balls.push_back (newBall);
}

bool Arena::removeBall(const int& id){
  for (unsigned int i = 0; i < balls.size(); ++i)
    if (balls[i].getId() == id){
      balls.erase (balls.begin() + i);
      return true;
    }
  return false;
}
