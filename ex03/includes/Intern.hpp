#ifndef INTERN_HPP
# define    INTERN_HPP

# include <iostream>
# include <string>
# include <exception>
# include <fstream>

class	AForm;

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);

		AForm*	makeForm(std::string name, std::string target);
};

#endif
