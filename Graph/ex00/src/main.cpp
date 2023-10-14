#include <iostream>
#include <fstream>
#include <map>

#include "Parser.hpp"
#include "Factory.hpp"
#include "Airport.hpp"

int main() {

  std::ifstream file("./conf/params.yml");
  Parser  parser;
  Factory factory;
  AInfrastructure *infra;
  Airport *ap = new Airport;
  factory.learn(ap);

  char  buffer[BUFFER_SIZE];  
  std::string token;

  file.read(buffer, BUFFER_SIZE);
  parser.set_tokenizer(buffer, PATTERN);

  while (true) {

    if (parser.get_token(token))
      break ;

    infra = factory.create(parser, token);
    std::cout << *(Airport *)infra;
  }

  return 0;
}