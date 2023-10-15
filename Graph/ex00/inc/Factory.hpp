#ifndef FACTORY_HPP
# define FACTORY_HPP

#include <map>
#include <string>

#include "AInfrastructure.hpp"
#include "Parser.hpp"
#include "defs.hpp"

class Factory
{
  public:
  
    Factory();
    ~Factory();

    bool    get_status() const;

    AInfrastructure  *create(Parser &parser, const std::string &token);
    bool  learn(AInfrastructure *infra);

  protected:

  private:

    std::map<std::string, AInfrastructure *>        _map_infra;
    typedef std::map<std::string, AInfrastructure *>::iterator  _it_infra;

    const std::string _regex;
    bool              _status;
    AInfrastructure   *_curr_type;
    std::string       _curr_type_name;

    bool    _get_type(const std::string &);
    size_t  _validate_param(std::string &param, const size_t depth);
    bool    _validate_character(t_params &params, std::string::iterator it, const size_t depth);
};

#endif //FACTORY_HPP