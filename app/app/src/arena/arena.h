#ifndef ARENA_H
#define ARENA_H

#include "./user/user.h"

struct ArenaInfo{
  int id;
  position playerPosition;
  vector <position> players;
};

class Arena {
  private:
    int id;
    int maxUsers = 10;
    vector <User> users;
  public:
    Arena();
    int getId() {return id;}
    bool addUser(User);
    ArenaInfo getArenaInfo(int userId);
    void updateUser(int userId, const std::string& move);
};

/*class User{
  private:
    int id;
    std::string name;
    //vector <>

};*/

#endif
