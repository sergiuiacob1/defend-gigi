#ifndef UTILS_H
#define UTILS_H
#include <iostream>

struct position{
	double x, y;
};

void log (const position& pos, std::string s = "Position"){
	cout<< s << pos.x << " " << pos.y << '\n';
	return;
}

void log (const double& x, std::string s = "Double"){
	cout << s << x <<'\n';
	return;
}

void log (const int& x, std::string s = "UInt"){
	cout << s << x <<'\n';
	return;
}

#endif