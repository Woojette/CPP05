#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{

}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
{

}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{

}

Bureaucrat::~Bureaucrat()
{

}

const std::string&  Bureaucrat::getName() const
{
  return (this->_name);
}

int Bureaucrat::getGrade() const
{
  return (this->_grade);
}

void  incrementGrade()
{

}

void  decrementGrade()
{
  
}