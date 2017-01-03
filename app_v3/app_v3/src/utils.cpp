#include "./utils.h"
#include <ctime>

double now(){
  return (double)clock();
}

void log(const std::string& x){
  std::cout << x <<'\n';
}
