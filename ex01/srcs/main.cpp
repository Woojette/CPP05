#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
  std::cout << "[1: le plus haut]  [150: le plus bas]" << std::endl << std::endl;

  std::cout << "############## 1. create bureau class (10) ##############" << std::endl << std::endl;
  Bureaucrat a("bureauA", 10);
  std::cout << a << std::endl;

  std::cout << std::endl << "############## 2. create form class ##############" << std::endl << std::endl;
  Form form("formA", 50, 20);
  std::cout << form << std::endl;

  std::cout << std::endl << "############## 3. test: bureau 10 ##############" << std::endl << std::endl;
  try
  {
    a.signForm(form);
    std::cout << form << std::endl;
  }
  catch (std::exception& e)
  {
    std::cout << e.what() << std::endl << std::endl;
  }

  std::cout << std::endl << "############## 4. test: bureau 70 ##############" << std::endl << std::endl;
  try
  {
    Bureaucrat b("bureauB", 70);
    b.signForm(form);
  }
  catch (std::exception& e)
  {
    std::cout << e.what() << std::endl << std::endl; 
  }

  std::cout << std::endl << "############## 5. test: bureau -2 ##############" << std::endl << std::endl;
  try
  {
    Bureaucrat c("bureauC", -2);
    c.signForm(form);
  }
  catch (std::exception& e)
  {
    std::cout << e.what() << std::endl << std::endl;
  }

  std::cout << std::endl << "############## 6. test: form 152, 20 ##############" << std::endl << std::endl;
  try
  {
    Form formToohigh("form too high", 152, 20);
  }
  catch (std::exception& e)
  {
    std::cout << e.what() << std::endl << std::endl;
  }

  std::cout << std::endl << "############## 7. test: form 50, 0 ##############" << std::endl << std::endl;
  try
  {
    Form formError("form error", 50, 0);
  }
  catch (std::exception& e)
  {
    std::cout << e.what() << std::endl << std::endl;
  }

  return (0);
}
