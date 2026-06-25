#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern() 
{
}
Intern::~Intern() 
{
}

Intern::Intern(const Intern &other) 
{
	(void)other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	std::string value[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};

	int i = 0;
	while (i < 3)
	{
		if (value[i] == name)
			break;
		i++;
	}

	switch (i)
	{
		case 0:
			std::cout << "Intern creates " << name << std::endl;
			return (new RobotomyRequestForm(target));
		case 1:
			std::cout << "Intern creates " << name << std::endl;
			return (new ShrubberyCreationForm(target));
		case 2:
			std::cout << "Intern creates " << name << std::endl;
			return (new PresidentialPardonForm(target));
		default:
			throw std::runtime_error("Form not found");
	}
}
