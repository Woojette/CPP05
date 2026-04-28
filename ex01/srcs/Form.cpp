#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("default"), _signed(false), _gradeSign(150), _gradeExecute(150)
{
  std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string& name, int gradeSign, int gradeExecute) : _name(name), _signed(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute)
{
  std::cout << "Form parametrized constructor called" << std::endl;
  if (_gradeSign < 1 || _gradeExecute < 1)
    throw GradeTooHighException();
  if (_gradeSign > 150 || _gradeExecute > 150)
    throw GradeTooLowException();
}

Form::Form(const Form& other) : _name(other._name), _signed(other._signed), _gradeSign(other._gradeSign), _gradeExecute(other._gradeExecute)
{
  std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form()
{
  std::cout << "Form destructor called" << std::endl;
}

Form& Form::operator=(const Form& other)
{
  std::cout << "Form copy assignment operator called" << std::endl;
  if (this != &other)
    this->_signed = other._signed;
  return (*this);
}

const char* Form::GradeTooHighException::what() const throw()
{
  return ("Grade too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
  return ("Grade too low");
}

const std::string&  Form::getName() const
{
  return (this->_name);
}

bool  Form::getSigned() const
{
  return (this->_signed);
}

int Form::getGradeSign() const
{
  return (this->_gradeSign);
}

int Form::getGradeExecute() const
{
  return (this->_gradeExecute);
}

void  Form::beSigned(const Bureaucrat& bureaucrat)
{
  if (bureaucrat.getGrade() > this->_gradeSign)
    throw GradeTooLowException();
  this->_signed = true;
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
  out << "Form name: " << form.getName() << ", signed: " << form.getSigned() << ", grade required to sign: " << form.getGradeSign() << ", grade required to execute: " << form.getGradeExecute() << ".";
  return (out);
}
