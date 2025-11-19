#include "form.hpp"
#include "bureaucrat.hpp"

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _isSigned(false)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::~Form()
{
}

int Form::getGradeToSign() const
{
    return _gradeToSign;
}

const std::string &Form::getName() const
{
    return _name;
}

bool Form::getIsSigned() const
{
    return _isSigned;
}

int Form::getGradeToExecute() const
{
    return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat &b)
{
    if(this->_isSigned)
        throw Form::AlreadySignedException() ;
    
    if(b.getGrade() > this->_gradeToSign)
    {
        throw Form::GradeTooLowException();
    }
    this->_isSigned = true;
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
    os << "Form Name: " << f.getName()
       << ", Signed: " << (f.getIsSigned() ? "Yes" : "No")
       << ", Grade to Sign: " << f.getGradeToSign()
       << ", Grade to Execute: " << f.getGradeToExecute();
    return os;
}
