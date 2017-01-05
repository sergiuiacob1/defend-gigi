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
    int getId() {return id;}
    bool addUser(User);
    std::string getArenaInfo(int userId);
    void updateUser(int userId, const std::string& move);
};

#endif
