#include <iostream>
#include "json.hpp"

using json = nlohmann::json;
using namespace std;

int main(int argc, char* argv[]){
  //cout <<argc<<'\n';
  //cout <<argv[1];
  json j = json::parse(argv[1]);
  cout <<j["type"]<<'\n';
  return 0;
}
