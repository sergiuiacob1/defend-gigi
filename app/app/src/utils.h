#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <cstring>
#include <vector>
#include <ctime>

double now();

struct position{
	double x, y;
};

void log (const position&, std::string);

void log (const double&, std::string);

void log (const int&, std::string);


#endif