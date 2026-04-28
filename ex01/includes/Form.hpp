#ifndef FORM_HPP
# define  FORM_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class Form
{
  private:
    const std::string _name;
    bool              _signed;
    const int         _gradeSign;
    const int         _gradeExecute;

  public:
    Form();
    Form(const std::string& name, int gradeSign, int gradeExecute);
    Form(const Form& other);
    ~Form();
    Form& operator=(const Form& other);

    class GradeTooHighException : public std::exception
    {
      public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
      public:
        virtual const char* what() const throw();
    };

    const std::string&  getName() const;
    bool  getSigned() const;
    int   getGradeSign() const;
    int   getGradeExecute() const;

    void  beSigned(const Bureaucrat& bureaucrat);
};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif
