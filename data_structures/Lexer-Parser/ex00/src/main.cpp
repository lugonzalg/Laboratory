#include <fstream>
#include <deque>

#include "Parser.hpp"
#include "Factory.hpp"
#include "AInfrastructure.hpp"
#include "Airport.hpp"


void create_connections(std::deque<AInfrastructure *> &ap_list, std::deque<Token *> token_list, Parser &parser) {
  std::fstream fs("./conf/flights.yml");
  char  buffer[BUFFER_SIZE + 1];
  ////AInfrastructure *infra;
  std::deque<AInfrastructure *>::iterator it;

  token_list.clear();
  fs.read(buffer, BUFFER_SIZE);
  parser.reload(buffer);
  parser.parse(token_list);

  it = ap_list.begin();
  for (; it < ap_list.end(); it++) {

  }
}


static void create_infras(std::deque<Token *> &token_list, std::deque<AInfrastructure *> &infra_group) {
  Factory             factory;
  Airport             *ap;

  ap = new Airport();
  factory.learn(ap);
  factory.create(token_list, infra_group);
}

int main() {
  std::deque<Token *>           token_list;
  std::deque<AInfrastructure *> infra_group;
  char  buffer[BUFFER_SIZE + 1];
  std::fstream fs("./conf/params.yml");

  fs.read(buffer, BUFFER_SIZE);
  Parser parser(buffer, REGEX_START, REGEX_END);
  parser.parse(token_list);
  create_infras(token_list, infra_group);
  create_connections(infra_group, token_list, parser);

  return 0;
}