#include <iostream>
#include <fstream>
#include <map>

# define ZERO          0
# define FINISHED      true
# define NOT_FINISHED  false
# define EQUAL         1
# define NOT_EQUAL     0
# define BUFFER_SIZE 1024
# define PATTERN "\n"
# define TOKEN_OK false
# define TOKENIZER_OK false

//Errors
# define ERR_BAD_ARGUMENTS  true
# define ERR_STILL_USING    true

# define NO_TYPE_SET  true
# define NO_CALLBACK  true
# define NO_TYPE_FOUND true
# define NO_TYPE      NULL
# define ARRAY            '-'
# define ATTRIBUTE        ':'
# define TAB              '\t'
# define BAD_REGEX        true
# define INCORRECT_DEPTH  true
# define BAD_ARRAY        true
# define NO_KEYS          true
# define BAD_PARAMETER    true
# define IS_OBJECT        1
# define IS_ATTRIBUTE     2
# define IS_ARRAY         3
# define UNKNOWN          0
# define VALIDATED_PARAM  false
# define VALIDATE_CHAR_OK false
# define TYPE_FOUND       false

typedef struct s_params {
  size_t  tabs;
  bool  attribute;
  bool  array;
} t_params;


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

class AInfrastructure
{
  public:

    virtual bool  fill(const std::string &param, const size_t type) = 0;
    virtual AInfrastructure *clone() = 0;
    const std::string &get_type();

  protected:

    AInfrastructure(const std::string &type);

  private:

    const std::string _type;
};

const std::string &AInfrastructure::get_type() {
  return this->_type;
}

AInfrastructure::AInfrastructure(const std::string &type): _type(type) {}

# define AIRPORT_NAME "airport:"

class Airport : public AInfrastructure
{
  public:

    Airport();

    typedef void(Airport::*callback)(const std::string &);
    std::map<std::string, callback> _map_fill_callback;
    typedef std::map<std::string, callback>::iterator _it_callback;

    bool  fill(const std::string &param, const size_t type);
    Airport *clone();

  protected:

  private:

    int _id;
    std::string _name;
    std::string _city;
    std::string _country;
    std::string _iata_code;

    void  _set_id(const std::string &id);
    void  _set_name(const std::string &name);
    void  _set_city(const std::string &city);
    void  _set_country(const std::string &country);
    void  _set_iata_code(const std::string &iata_code);
};

# define ISSPACE " \t\r\n:"

bool  Airport::fill(const std::string &param, const size_t type) {
  Parser  parser;
  _it_callback  it;
  std::string key;
  std::string value;

  parser.set_tokenizer(param, ISSPACE);
  if (type == 3)
    parser.get_token(key);

  parser.get_token(key);
  it = this->_map_fill_callback.find(key);
  if (it == this->_map_fill_callback.end())
    return true;

  parser.get_token(value);
  (this->*(it->second))(value);

  return false;
}
Airport *Airport::clone() { return new Airport; }

Airport::Airport(): AInfrastructure(AIRPORT_NAME) {
  this->_map_fill_callback["id"] = &Airport::_set_id;
  this->_map_fill_callback["name"] = &Airport::_set_name;
  this->_map_fill_callback["city"] = &Airport::_set_city;
  this->_map_fill_callback["country"] = &Airport::_set_country;
  this->_map_fill_callback["iata_code"] = &Airport::_set_iata_code;
}

//setters

void  Airport::_set_id(const std::string &param) { this->_id = std::stoi(param); }
void  Airport::_set_name(const std::string &param) { this->_name = param; }
void  Airport::_set_city(const std::string &param) { this->_city = param; }
void  Airport::_set_country(const std::string &param) { this->_country = param; }
void  Airport::_set_iata_code(const std::string &param) { this->_iata_code = param; }
  
class Factory
{
  public:
  
    Factory();
    ~Factory(){}

    AInfrastructure  *create(Parser &parser, const std::string &token);
    bool  learn(AInfrastructure *infra);

  protected:

  private:

    std::map<std::string, AInfrastructure *>        _map_infra;
    typedef std::map<std::string, AInfrastructure *>::iterator  _it_infra;

    const std::string _regex;
    AInfrastructure   *_curr_type;
    std::string       _curr_type_name;

    bool    _get_type(const std::string &);
    ssize_t _validate_param(std::string &param, const size_t depth);
    bool    _validate_character(t_params &params, std::string::iterator it, const size_t depth);
};

Factory::Factory(): _regex("poiuytrewqlkjhgfdsamnbvcxzPOIUYTREWQLKJHGFDSAMNBVCXZ:- \t0987654321_.") {
}

bool  Factory::_get_type(const std::string &token) {
  _it_infra         it;

  it = this->_map_infra.find(token);
  if (it == this->_map_infra.end())
    return NO_TYPE_FOUND;

  this->_curr_type_name = it->second->get_type();
  return TYPE_FOUND;
}

bool  Factory::_validate_character(t_params &params, std::string::iterator it, const size_t depth) {
  if (this->_regex.find(*it) == static_cast<size_t>(-1))
    return BAD_REGEX;

  if (*it == TAB)
    params.tabs++;

  if (params.tabs > depth)
    return INCORRECT_DEPTH;
  else if (params.tabs and params.attribute and *it == ARRAY)
    return BAD_ARRAY;

  if (*it == ARRAY)
    params.array = true;
  else if (*it == ATTRIBUTE)
    params.attribute = true;
  return VALIDATE_CHAR_OK;
}

ssize_t  Factory::_validate_param(std::string &src, const size_t depth) {
  std::string::iterator it;
  t_params  params;

  std::memset(&params, 0, sizeof(t_params));
  for (it = src.begin(); it != src.end(); it++) {
    if (this->_validate_character(params, it, depth))
      return BAD_PARAMETER;
  }

  if (!params.array and !params.attribute)
    return NO_KEYS;

  if (!params.array and (src.back() == ATTRIBUTE))
    return IS_OBJECT;
  else if (params.attribute and !params.array and (src.back() != ATTRIBUTE))
    return IS_ATTRIBUTE;
  else if (params.attribute and params.array)
    return IS_ARRAY;
  return UNKNOWN;
}

AInfrastructure  *Factory::create(Parser &parser, const std::string &token) {

  std::string param;

  if (this->_get_type(token))
    return NULL;

  //TODO create type
  while (true) {
    parser.get_token(param);
    switch (this->_validate_param(param, 1))
    {
      case 0:
        /* code */
        std::cerr << "Error: unknown parameter!\r\n";
        break;

      case 1:
        /* code */
        this->_curr_type->fill(param, 1);
        break;

      case 2:
        /* code */
        this->_curr_type->fill(param, 2);
        break;

      case 3:
        this->_curr_type = this->_map_infra[this->_curr_type_name]->clone();
        this->_curr_type->fill(param, 3);
        break;
    
      default:
          break;
    }
  }

  return NULL;
}

# define EXISTS true
# define SUCCESS false

bool  Factory::learn(AInfrastructure *infra) {
  _it_infra it;
  std::string type_name;

  type_name = infra->get_type();
  it = this->_map_infra.find(type_name);
  if (it != this->_map_infra.end())
    return EXISTS;

  this->_map_infra[type_name] = infra->clone();
  return SUCCESS;
}

int main() {

  std::ifstream file("../conf/params.yml");
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
    std::cout << token << std::endl;
  }

  return 0;
}