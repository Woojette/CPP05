#include "Bureaucrat.hpp"

int main(void)
{
  std::cout << "[1: le plus haut]  [150: le plus bas]" << std::endl << std::endl;

  std::cout << "############## 1. create bureau class (10) ##############" << std::endl << std::endl;
  Bureaucrat a("bureau", 10);
  std::cout << a << std::endl;

  std::cout << std::endl << "+++++++++++++++ increment +++++++++++++++" << std::endl << std::endl;
  try
  {
    a.incrementGrade();
    std::cout << a << std::endl;
  }
  catch (std::exception& e)
  {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  std::cout << std::endl << "--------------- decrement ---------------" << std::endl << std::endl;
  try
  {
    a.decrementGrade();
    std::cout << a << std::endl;
  }
  catch (std::exception& e)
  {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  std::cout << std::endl << "############## 2. test: too high (1) ##############" << std::endl << std::endl;
  Bureaucrat b("high", 1);
  std::cout << b << std::endl;

  std::cout << std::endl << "+++++++++++++++ increment (1 -> 0) +++++++++++++++" << std::endl << std::endl;
  try
  {
    b.incrementGrade();
    std::cout << b << std::endl;
  }
  catch (std::exception& e)
  {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  std::cout << std::endl << "############## 3. test: too low (150) ##############" << std::endl << std::endl;
  Bureaucrat d("high", 150);
  std::cout << d << std::endl;

  std::cout << std::endl << "--------------- decrement (150 -> 151) ---------------" << std::endl << std::endl;
  try
  {
    d.decrementGrade();
    std::cout << d << std::endl;
  }
  catch (std::exception& e)
  {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  std::cout << std::endl << "############## test: too high (0) ##############" << std::endl << std::endl;
  try
  {
    Bureaucrat f("high", 0);
    f.incrementGrade();
    std::cout << f << std::endl;
  }
  catch (std::exception& e)
  {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  std::cout << std::endl;

  return (0);
}
