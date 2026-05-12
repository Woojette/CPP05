#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>

int main(void)
{
  srand(time(NULL));

  std::cout << "############### Create Bureaucrats: superior, inferior ###############" << std::endl << std::endl;
  Bureaucrat bSuperior("superior", 1);
  Bureaucrat bInferior("inferior", 150);

  std::cout << std::endl << bSuperior << std::endl;
  std::cout << bInferior << std::endl;

  std::cout << std::endl << "############### Create AForms ###############" << std::endl << std::endl;
  ShrubberyCreationForm tree("tree");
  RobotomyRequestForm robot("robot");
  PresidentialPardonForm pardon("pardon");

  std::cout << std::endl << tree << std::endl;
  std::cout << robot << std::endl;
  std::cout << pardon << std::endl;

  std::cout << std::endl << "############### test: execute before sign  ###############" << std::endl << std::endl;
  bSuperior.executeForm(tree);

  std::cout << std::endl << "############### superior AForms ###############" << std::endl << std::endl;

  bSuperior.signAForm(tree);
  std::cout << std::endl << "check: tree_shrubbery" << std::endl << std::endl;

  // test after create file
  std::ifstream file("tree_shrubbery");

  std::string line;
  while (std::getline(file, line))
    std::cout << line << std::endl;
  std::cout << std::endl;
  file.close();

  bSuperior.signAForm(robot);
  bSuperior.signAForm(pardon);

  std::cout << std::endl << "############### test: executes AForms of superior ###############" << std::endl << std::endl;
  std::cout << "shrubbery ===============" << std::endl;
  bSuperior.executeForm(tree);
  std::cout << std::endl << "robot: 50% (test several times) ===============" << std::endl;
  bSuperior.executeForm(robot);
  std::cout << std::endl << "pardon ===============" << std::endl;
  bSuperior.executeForm(pardon);

  std::cout << std::endl << "############### test: robotomy multiple tests ###############" << std::endl << std::endl;
  for (size_t i = 0; i < 10; i++)
    bSuperior.executeForm(robot);

  std::cout << std::endl << "############### inferior AForms (fail) ###############" << std::endl << std::endl;
  bInferior.signAForm(tree);
  bInferior.signAForm(robot);
  bInferior.signAForm(pardon);

  std::cout << std::endl << "############### destructor ###############" << std::endl << std::endl;

  return (0);
}
