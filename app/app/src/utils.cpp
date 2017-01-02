#include "./utils.h"


struct position{
	double x, y;
};

double now(){
  return (double)clock();
}

void log (const position& pos, std::string s = "Position"){
  std::cout << s << pos.x << " " << pos.y << '\n';
	return;
}

void log (const double& x, std::string s = "Double"){
  std::cout << s << x <<'\n';
	return;
}

void log (const int& x, std::string s = "UInt"){
  std::cout << s << x <<'\n';
	return;
}

