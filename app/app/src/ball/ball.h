#ifndef BALL_H
#define BALL_H
#include "./../utils.h"

class ball{
	unsigned int id;
	unsigned int speed;
	double slope;
	position pos;

	void update ();

#endif