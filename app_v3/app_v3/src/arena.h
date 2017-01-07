#ifndef ARENA_H
#define ARENA_H

#define maxUsers 10
#include "./user.h"
#include <iostream>
#include <vector>

class Arena {
  private:
    int id;
    int lastUpdate;
    std::vector <User> users;
  public:
    Arena();
    const int getId() {return id;}
    bool addUser(User);
    std::string getArenaInfo(const std::string& userId);
    void updateUser(const std::string& userId, const std::string& move);
    const int getNrUsers() {return users.size();}
};

#endif
