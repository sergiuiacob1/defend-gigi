#include "./utils.h"

using namespace std;

double now(){
  return clock();
}

void log (const position& pos, string s = "Position"){
	cout << s << pos.x << " " << pos.y << '\n';
	return;
}

void log (const double& x, string s = "Double"){
	cout << s << x <<'\n';
	return;
}

void log (const int& x, string s = "UInt"){
	cout << s << x <<'\n';
	return;
}

