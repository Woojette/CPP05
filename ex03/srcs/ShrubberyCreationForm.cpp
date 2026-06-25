#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
  // std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
  // std::cout << "ShrubberyCreationForm parametrized constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target)
{
  // std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
  // std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm&  ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
  // std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
  if (this != &other)
    this->_target = other._target;
  return (*this);
}

void  ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
  if (!getSigned())
    throw AForm::AFormNotSignedException();

  if (executor.getGrade() > getGradeExecute())
    throw AForm::GradeTooLowException();

  std::ofstream file((_target + "_shrubbery").c_str());
  if (!file)
    return ;

  file << "              v .   ._, |_  .," << std::endl;
  file << "           `-._\\/  .  \\ /    |/_" << std::endl;
  file << "               \\\\  _\\, y | \\//" << std::endl;
  file << "         _\\_.___\\\\, \\\\/ -.\\||" << std::endl;
  file << "           `7-,--.`._||  / / ," << std::endl;
  file << "           /'     `-. `./ / |/_.'" << std::endl;
  file << "                     |    |//" << std::endl;
  file << "                     |_    /" << std::endl;
  file << "                     |-   |" << std::endl;
  file << "                     |   =|" << std::endl;
  file << "                     |    |" << std::endl;
  file << "--------------------/ ,  . \\--------._" << std::endl;

  file.close();
}
