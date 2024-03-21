#ifndef AINFRAESTRUCTURE_HPP
# define AINFRAESTRUCTURE_HPP

#include <string>

class AInfrastructure
{
  public:

    virtual ~AInfrastructure() {}

    virtual AInfrastructure *clone() = 0;
    virtual void  add_value(const std::string &value) = 0;
    virtual void  set_value(const std::string &value) = 0;
    const std::string &get_type();
    const std::string &get_name();

  protected:

    AInfrastructure(const std::string &type);

    std::string __name;
    const std::string __type;

  private:

};

#endif //AINFRAESTRUCTURE_HPP