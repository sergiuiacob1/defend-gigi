#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <cstring>
#include <vector>
#include <ctime>

struct position;

void log(const position& pos, std::string s);

void log(const double& x, std::string s);

void log(const int& x, std::string s);

double now();


#endif
