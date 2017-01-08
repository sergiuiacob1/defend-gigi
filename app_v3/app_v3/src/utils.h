#ifndef UTILS_H
#define UTILS_H
#define CANVAS_WIDTH 800
#define CANVAS_HEIGHT 800
#include <iostream>
#include <cstring>
#include "./stack.h"

struct position{
	double x, y;
};

struct nod{
	int value;
	struct nod *next;
};

void log(const std::string& x);

double now();


#endif
