#ifndef AIRPORT_HPP
# define AIRPORT_HPP

#include <string>
#include <map>

#include "AInfrastructure.hpp"
#include "defs.hpp"

class Airport : public AInfrastructure
{
  public:

    Airport();

    typedef void(Airport::*callback)(const std::string &);
    std::map<std::string, callback> _map_fill_callback;
    typedef std::map<std::string, callback>::iterator _it_callback;

    bool  fill(const std::string &param, const size_t type);
    Airport *clone();

    std::string get_log();

  protected:

  private:

    int         _id;
    float       _latitude;
    float       _longitude;
    std::string _city;
    std::string _country;
    std::string _description;

    void  _set_id(const std::string &id);
    void  _set_description(const std::string &description);
    void  _set_city(const std::string &city);
    void  _set_country(const std::string &country);
    void  _set_iata_code(const std::string &name);
    void  _set_latitude(const std::string &latitude);
    void  _set_longitude(const std::string &longitude);
};

std::ostream &operator<<(std::ostream &os, Airport &ap);

#endif //AIRPORT_HPP