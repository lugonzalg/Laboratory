#ifndef AIRPORT_HPP
# define AIRPORT_HPP

#include <string>
#include <map>
#include <deque>

#include "AInfrastructure.hpp"
#include "defs.hpp"

class Airport : public AInfrastructure
{
  public:

    Airport();

    Airport *clone();

    std::string get_log();
    void  add_value(const std::string &value);
    void  set_value(const std::string &value);

  protected:

  private:
    
    typedef void(Airport::*callback)(const std::string &);
    std::map<std::string, callback>                   __setters;
    typedef std::map<std::string, callback>::iterator __it_setter;

    int         __id;
    float       __latitude;
    float       __longitude;
    std::string __city;
    std::string __country;
    std::string __description;
    __it_setter __curr_setter;
    std::deque<AInfrastructure *> __edges;

    void  __set_id(const std::string &id);
    void  __set_description(const std::string &description);
    void  __set_city(const std::string &city);
    void  __set_country(const std::string &country);
    void  __set_iata_code(const std::string &name);
    void  __set_latitude(const std::string &latitude);
    void  __set_longitude(const std::string &longitude);

};

std::ostream &operator<<(std::ostream &os, Airport &ap);

#endif //AIRPORT_HPP