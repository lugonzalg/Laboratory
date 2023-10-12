#include <iostream>

#include "Handler.hpp"
#include "defs.hpp"

Handler::Handler() {
  this->nodeFactory["airports:"] = &Handler::create_airport;
}

Handler::~Handler() {}

size_t  Handler::delimiter(const std::string &src, const std::string pattern, size_t i, bool mode) {
  const size_t retval = -1;

  for (; i < src.size() and (pattern.find(src[i]) == retval) == mode; i++);
  return i;
}

std::deque<std::string> *Handler::split(const std::string &src, const std::string &patter) {
  size_t  start;
  size_t  end;
  std::deque<std::string> *bucket;

  bucket = new std::deque<std::string>;
  for (size_t i = 0; i < src.size(); i++) {
    start = delimiter(src, patter, i, 0);
    end = start;
    end = delimiter(src, patter, start, 1);

    if (start >= end)
      break ;

    std::string token(src, start, end - start);
    bucket->push_back(token);
    i = end;
  }
  return bucket;
}

std::string Handler::create_airport(std::ifstream &file) {

  std::deque<std::string> *bucket;
  std::string token;
  Handler::callback callback;
  Airport *airport;

  while (std::getline(file, token)) {

    bucket = this->split(token, KEYS);
    std::cout << "size: " << bucket->size() << std::endl;
    switch (bucket->size())
    {
      case 1:
      {
        delete bucket;
        return token;
      }
      case 2:
      {
        airport->handle_keyword(bucket);
        break ;
      }
      case 3:
      {
        airport = new Airport;
        net.add_airport(airport);
        bucket->pop_front();
        airport->handle_keyword(bucket);
        break ;
      }
      
      default:
        return NULL;
        break;
      }
  }
  return NULL;
}
