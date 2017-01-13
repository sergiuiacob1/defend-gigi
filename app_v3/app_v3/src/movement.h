#ifndef MOVEMENT_H
#define MOVEMENT_H
#include "./utils.h"

class Movement {
  private:
    double xCurr = 0, yCurr = 0;
    int xDest, yDest;
    bool running;
    double vitezaSec;
    double viteza;
    double mx, my;
    double rap;
    int semnx, semny;

    position onUpdate();

  public:
    Movement(int xCurr, int yCurr, int xDest, int yDest, int viteza);
    bool isRunning() {return running;}
    double getX() {return xCurr;}
    double getY() {return yCurr;}
    position update();

};

#endif
