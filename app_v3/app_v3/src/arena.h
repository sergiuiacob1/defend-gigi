#ifndef ARENA_H
#define ARENA_H

#define maxUsers 10
#define maxArenas 100
#include "./user.h"
#include "./ball.h"
#include <iostream>
#include <vector>

class Arena {
  private:
    static int totalNrOfBalls;

    int id;
    int lastUpdate;
    std::vector <User> users;
    std::vector <ball> balls;
  public:
    Arena();
    const int getId() {return id;}
    static int getTotalNrOfBalls() {return totalNrOfBalls;}
    bool addUser(User);
    bool removeUser(const std::string&);
    std::string getArenaInfo(const std::string& userId);
    bool updateUser(const std::string& userId, const std::string& move);
    const int getNrUsers() {return users.size();}
    void addBall (const ball& newBall) {balls.push_back (newBall); ++totalNrOfBalls;}
    bool removeBall (const int& id);

    //void processCollisions();
};

#endif
