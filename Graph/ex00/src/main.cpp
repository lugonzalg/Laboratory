#include <iostream>

#include "Handler.hpp"

int main() {

  std::ifstream file("./conf/params.yml");
  Handler::callback callback;
  std::string token;
  Handler handler;


  while (std::getline(file, token)) {
    std::cout << token << std::endl;
    callback = handler.nodeFactory.find(token);
    if (callback != handler.nodeFactory.end())
      (handler.*(callback->second))(file);
  }

  return 0;
}
