#ifndef AIRPORT_HPP
# define AIRPORT_HPP

#include <string>
#include <map>
#include <deque>

#include "Params.hpp"

class Airport
{
  public:
    
    typedef std::pair<float, float>                         t_coordinates;
    typedef void (Airport::*MemberFunction)(const AParam &);
    typedef std::map<std::string, MemberFunction>           c_key_value;
    typedef std::map<std::string, MemberFunction>::iterator it_key_value;

    int                     id;
    std::string             name;
    std::string             city;
    std::string             country;
    std::string             iata_code;
    std::pair<float, float> coordinates;
    Airport                 *next;
    c_key_value             kv_callback;

    Airport();
    ~Airport();

    void    handle_keyword(std::deque<std::string> *keywords);

    //setter
    void  set_id(const AParam &param);
    void  set_name(const AParam &param);
    void  set_city(const AParam &param);
    void  set_country(const AParam &param);
    void  set_iata_code(const AParam &param);
    void  set_coordinates(const AParam &param);

  protected:

  private:

};

#endif //AIRPORT_HPP
