#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>
#include "Intern.hpp"

int main(void)
{
	Intern someRandomIntern;
	// AForm* rrf;
	// AForm* President;
	// AForm* Shrub;


	std::cout << std::endl << "############### TEST: valid (robotomy, presidential, shrubbery) ###############" << std::endl << std::endl;
	try
	{
		AForm*	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		AForm*	President = someRandomIntern.makeForm("presidential pardon", "Bewan");
		AForm*	Shrub = someRandomIntern.makeForm("shrubbery creation", "popo");

		delete President;
		delete Shrub;
		delete rrf;
	}
	catch (const std::exception &e) 
	{
		std::cerr << e.what() << std::endl; 
		return (1);
	}

	std::cout << std::endl << "############### TEST: invalid (arg not exist) ###############" << std::endl << std::endl;

	try 
	{
		AForm*	nothing = someRandomIntern.makeForm("Do nothing", "Hmm");


		delete	nothing;
	}
	catch (const std::exception &e) 
	{
		std::cerr << e.what() << std::endl; 
		return (1);
	}

	return (0);
}
