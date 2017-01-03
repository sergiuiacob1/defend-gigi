#ifndef USER_H
#define USER_H

#include "./utils.h"

class User{
  private:
    position pos;
    std::string name;
    int id;
    void onUpdate(const std::string& move);
    int lastUpdate;
  public:
    User(const std::string& name, const position& pos);
    int getId() {return id;}
    position getPosition() {return pos;}
    void update(const std::string& move);
};

#endif
