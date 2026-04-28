#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
  std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
  std::cout << "Bureaucrat parametrized constructor called" << std::endl;
  if (_grade < 1)
    throw GradeTooHighException();
  if (_grade > 150)
    throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
  std::cout << "Bureaucrat copy constructor called" << std::endl;
  if (_grade < 1)
    throw GradeTooHighException();
  if (_grade > 150)
    throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
  std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
  std::cout << "Bureaucrat copy assignment operator called" << std::endl;
  if (this != &other)
    this->_grade = other._grade;
  if (_grade < 1)
    throw GradeTooHighException();
  if (_grade > 150)
    throw GradeTooLowException();
  return (*this);
}

const std::string&  Bureaucrat::getName() const
{
  return (this->_name);
}

int Bureaucrat::getGrade() const
{
  return (this->_grade);
}

void  Bureaucrat::incrementGrade()
{
  if (this->_grade < 2)
    throw GradeTooHighException();
  this->_grade--;
}

void  Bureaucrat::decrementGrade()
{
  if (this->_grade > 149)
    throw GradeTooLowException();
  this->_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
  return ("Grade too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
  return ("Grade too low");
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
  out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
  return (out);
}

void  Bureaucrat::signForm(Form& form)
{
  try
  {
    form.beSigned(*this);
    std::cout << this->_name << " signed " << form.getName() << std::endl;
  }
  catch (std::exception& e)
  {
    std::cout << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
  }
}
