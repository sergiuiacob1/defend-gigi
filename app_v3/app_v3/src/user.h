#ifndef USER_H
#define USER_H

#include "./utils.h"
#include "./sheep.h"
#include "./gigi.h"

class User{
  private:
    position pos;
    std::string name;
    std::string id;
    int lastUpdate;
    Sheep sheep;
    Gigi gigi;
    void onUpdate(const std::string& move);
  public:
    User(const std::string& name, const std::string& id, const position& pos);
    std::string getId() const {return id;}
    position getPosition() {return pos;}
    position getSheepPosition() {return sheep.getPosition();}
    position getGigiPosition() {return gigi.getPosition();}

    void setSheepPosition (const position& newPos) {sheep.setPosition (newPos);}
    void setGigiPosition (const position& newPos) {gigi.setPosition (newPos);}

    void update(const std::string& move);
};

#endif