#include <iostream>
#include <fstream>
#include <map>

#include "Parser.hpp"
#include "Factory.hpp"
#include "Airport.hpp"
#include "Network.hpp"

int main() {

  std::ifstream file("./conf/params.yml");
  Parser  parser;
  Factory factory;
  AInfrastructure *infra;
  Airport *ap = new Airport;
  factory.learn(ap);
  Network net;

  char  buffer[BUFFER_SIZE + 1];  
  std::string token;

  file.read(buffer, BUFFER_SIZE);
  parser.set_tokenizer(buffer, PATTERN);


  parser.get_token(token);
  while (true) {

    infra = factory.create(parser, token);
    std::cout << *(Airport *)infra;
    net.set_infra(infra);
    if (factory.get_status() == false)
      break ;
  }
  file.open("./conf/flights.yml");
  file.read(buffer, BUFFER_SIZE);
  parser.set_tokenizer(buffer, PATTERN);

  net.erase();
  delete ap;

  return 0;
}