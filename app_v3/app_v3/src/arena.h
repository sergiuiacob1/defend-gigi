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
    void onUpdate();
  public:
    Arena();
    const int getId() {return id;}
    static int getTotalNrOfBalls() {return totalNrOfBalls;}
    int getNrUsers() const {return users.size();}
    std::string getArenaInfo(const std::string& userId);

    bool addUser(User);
    bool removeUser(const std::string&);
    bool updateUser(const std::string& userId, const std::string& move);

    void addBall (const ball& newBall) {balls.push_back (newBall); ++totalNrOfBalls;}
    void addBall (const std::string& userId, const int& x, const int& y);
    bool removeBall (const int& id);

    void processCollisions();
    inline void addScoreToUser (const std::string&);

    void update();
};

#endif
