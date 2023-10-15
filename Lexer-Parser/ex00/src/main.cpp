#include <fstream>

#include "Parser.hpp"

# define BUFFER_SIZE 1024

int main() {
  char  buffer[BUFFER_SIZE + 1];
  std::fstream fs("./conf/test.yml");

  fs.read(buffer, BUFFER_SIZE);
  Parser parser(buffer);
  parser.parse();

  return 0;
}
