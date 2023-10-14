#ifndef AINFRAESTRUCTURE_HPP
# define AINFRAESTRUCTURE_HPP

#include <string>

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

#endif //AINFRAESTRUCTURE_HPP