#ifndef PARSER_HPP
# define PARSER_HPP

#include <string>

#include "defs.hpp"

class Parser
{

  public:

    Parser();
    ~Parser(){}

    bool  set_tokenizer(const std::string &src, const std::string &pattern);
    bool  get_token(std::string &dst);

  protected:

  private:

    size_t        _start;
    size_t        _end;

    std::string _src;
    std::string _pattern;

    bool  _finished;
    const size_t  _different;

    size_t  _delimiter(bool mode);

};


#endif //PARSER_HPP