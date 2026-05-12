#ifndef AFORM_HPP
# define  AFORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include <fstream>

class Bureaucrat;

class AForm
{
  private:
    const std::string _name;
    bool              _signed;
    const int         _gradeSign;
    const int         _gradeExecute;

  public:
    AForm();
    AForm(const std::string& name, int gradeSign, int gradeExecute);
    AForm(const AForm& other);
    virtual ~AForm();
    AForm& operator=(const AForm& other);

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

    class AFormNotSignedException : public std::exception
    {
      public:
        virtual const char* what() const throw();
    };

    const std::string&  getName() const;
    bool  getSigned() const;
    int   getGradeSign() const;
    int   getGradeExecute() const;

    void  beSigned(const Bureaucrat& bureaucrat);

    virtual void  execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif
