#include "Parser.hpp"

Parser::Parser() : _start(ZERO), _end(ZERO), _finished(FINISHED), _different(-1) {

}

bool  Parser::set_tokenizer(const std::string &src, const std::string &pattern) {

  if (src.size() == 0 or pattern.size() == 0)
    return ERR_BAD_ARGUMENTS;

  else if (this->_finished == NOT_FINISHED)
    return ERR_STILL_USING;

  this->_src = src;
  this->_pattern = pattern;
  this->_finished = NOT_FINISHED;
  return TOKENIZER_OK;
}

size_t  Parser::_delimiter(bool mode) {
  size_t  size;

  for(size = this->_start; size < this->_src.size() and (this->_pattern.find(this->_src[size]) == this->_different) == mode; size++);
  return size;
}

bool  Parser::get_token(std::string &dst) {

  if (this->_finished == FINISHED)
    return FINISHED;

  this->_start = this->_delimiter(NOT_EQUAL);
  this->_end = this->_delimiter(EQUAL);

  if (this->_start >= this->_end)
    return FINISHED;

  dst = this->_src.substr(this->_start, this->_end - this->_start);
  this->_start = this->_end;
  return TOKEN_OK;
}