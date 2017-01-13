#include "./movement.h"
#include "json.hpp"
#include <cmath>
#define mod(x) (((x)< 0)?(-(x)):((x)))
using json = nlohmann::json;

Movement::Movement(int xCurr, int yCurr, int xDest, int yDest, int viteza){
  this->xCurr = xCurr;
  this->yCurr = yCurr;

  this->xDest = xDest;
  this->yDest = yDest;

  vitezaSec = viteza;

  this->viteza = vitezaSec / 60;
  running = true;

  if (yDest == yCurr)
    rap = 0;
  else
    rap = (double) (xDest - xCurr) / (yDest - yCurr);

  rap = mod(rap);

  if (xDest < xCurr)
    semnx = -1;
  else
    semnx = 1;

  if (yDest < yCurr)
    semny = -1;
  else
    semny = 1;
}

void Movement::onUpdate(){
  if (running == false)
    return;

  if (xCurr == xDest){
    mx = 0;
    my = viteza;
  }
  else if (yCurr == yDest){
    mx = viteza;
    my = 0;
  }
  else{
    mx = sqrt(mod(viteza * viteza * rap * rap) / (rap * rap + 1));
    my = sqrt(mod(viteza * viteza - mx * mx));
  }

  if (mx > viteza)
    mx = 0;
  if (my > viteza)
    my = 0;

  xCurr += semnx * mx;
  yCurr += semny * my;

  /*int auxX = mod(xCurr - xDest);// auxX = auxX<0?(-auxX):auxX;
  int auxY = mod(yCurr - yDest);// auxY = auxY<0?(-auxY):auxY;
  if (auxX <= 6 && auxY <= 6)
    running = false;*/
}

void Movement::update(){
  onUpdate();
}
