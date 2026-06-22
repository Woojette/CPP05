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

		AForm*	makeform(std::string name, std::string form);
};

#endif
