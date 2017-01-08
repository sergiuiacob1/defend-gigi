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
    int lastUpdate, score;
    Sheep sheep;
    Gigi gigi;
    void onUpdate(const std::string& move);
  public:
    User(const std::string& name, const std::string& id, const position& pos);
    std::string getId() const {return id;}
    Sheep getSheep() const {return sheep;}
    Gigi getGigi() const {return gigi;}
    position getPosition() const {return pos;}
    position getSheepPosition() const {return sheep.getPosition();}
    position getGigiPosition() const {return gigi.getPosition();}
    int getScore() const {return score;}

    void setSheepPosition (const position& newPos) {sheep.setPosition (newPos);}
    void setGigiPosition (const position& newPos) {gigi.setPosition (newPos);}
    void setScore (const int& newScore) {score=newScore;}

    void update(const std::string& move);
};

#endif
