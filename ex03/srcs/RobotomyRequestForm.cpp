#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
  // std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
  // std::cout << "RobotomyRequestForm parametrized constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target)
{
  // std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
  // std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm&  RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
  // std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
  if (this != &other)
    this->_target = other._target;
  return (*this);
}

void  RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
  if (!getSigned())
    throw AForm::AFormNotSignedException();
  if (executor.getGrade() > getGradeExecute())
    throw AForm::GradeTooLowException();
  std::cout << "Drriiiiiiiillllllll" << std::endl;

  if (rand() % 2 == 0)
    std::cout << this->_target << " has been robotomized successfully." << std::endl;
  else
    std::cout << this->_target << ": the robotomy failed." << std::endl;
}
