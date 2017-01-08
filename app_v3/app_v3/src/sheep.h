#ifndef SHEEP_H
#define SHEEP_H
#include "./collidable.h"

class Sheep:public collidable {

    public:
    void move (const std::string&);
};

#endif