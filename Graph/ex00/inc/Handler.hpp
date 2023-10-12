# ifndef HANDLER_HPP
#define HANDLER_HPP

#include <map>
#include <deque>
#include <fstream>

#include "Airport.hpp"
#include "Network.hpp"

class Handler
{
  public:

    typedef std::string (Handler::*MemberFunction)(std::ifstream &);
    std::map<std::string, MemberFunction> nodeFactory;
    typedef std::map<std::string, MemberFunction>::iterator callback;

    Network net;

    std::string create_airport(std::ifstream &file);
    std::deque<std::string>   *split(const std::string &src, const std::string &patter);
    size_t                    delimiter(const std::string &src, const std::string patter, size_t i, bool mode);

    Handler();
    ~Handler();
};

#endif //HANDLER_HPP
