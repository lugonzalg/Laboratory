#include <fstream>

#include "Parser.hpp"

# define BUFFER_SIZE 40960
# define REGEX "poiuytrewqlkjhgfdsamnbvcxz0987654321.POIUYTREWQLKJHGFDSAMNBVCXZ_'"

int main() {
  char  buffer[BUFFER_SIZE + 1];
  std::fstream fs("./conf/params.yml");

  fs.read(buffer, BUFFER_SIZE);
  Parser parser(buffer, REGEX);
  parser.parse();

  return 0;
}
