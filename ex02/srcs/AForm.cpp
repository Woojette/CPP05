#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeSign(150), _gradeExecute(150)
{
  std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string& name, int gradeSign, int gradeExecute) : _name(name), _signed(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute)
{
  std::cout << "AForm parametrized constructor called" << std::endl;
  if (_gradeSign < 1 || _gradeExecute < 1)
    throw GradeTooHighException();
  if (_gradeSign > 150 || _gradeExecute > 150)
    throw GradeTooLowException();
}

AForm::AForm(const AForm& other) : _name(other._name), _signed(other._signed), _gradeSign(other._gradeSign), _gradeExecute(other._gradeExecute)
{
  std::cout << "AForm copy constructor called" << std::endl;
}

AForm::~AForm()
{
  std::cout << "AForm destructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
  std::cout << "AForm copy assignment operator called" << std::endl;
  if (this != &other)
    this->_signed = other._signed;
  return (*this);
}

const char* AForm::GradeTooHighException::what() const throw()
{
  return ("Grade too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
  return ("Grade too low");
}

const char* AForm::AFormNotSignedException::what() const throw()
{
  return ("AForm not signed");
}

const std::string&  AForm::getName() const
{
  return (this->_name);
}

bool  AForm::getSigned() const
{
  return (this->_signed);
}

int AForm::getGradeSign() const
{
  return (this->_gradeSign);
}

int AForm::getGradeExecute() const
{
  return (this->_gradeExecute);
}

void  AForm::beSigned(const Bureaucrat& bureaucrat)
{
  if (bureaucrat.getGrade() > this->_gradeSign)
    throw GradeTooLowException();
  this->_signed = true;
}

std::ostream& operator<<(std::ostream& out, const AForm& Aform)
{
  out << "AForm name: " << Aform.getName() << ", signed: " << Aform.getSigned() << ", grade required to sign: " << Aform.getGradeSign() << ", grade required to execute: " << Aform.getGradeExecute() << ".";
  return (out);
}
