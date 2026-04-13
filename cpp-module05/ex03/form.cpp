#include "form.hpp"
#include "bureaucrat.hpp"

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
    : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _isSigned(false)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other)
    : _name(other._name), _gradeToSign(other._gradeToSign),
      _gradeToExecute(other._gradeToExecute), _isSigned(other._isSigned)
{
}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
        _isSigned = other._isSigned;
    return *this;
}

AForm::~AForm() {}


int AForm::getGradeToSign() const
{
    return _gradeToSign;
}

const std::string &AForm::getName() const
{
    return _name;
}

bool AForm::getIsSigned() const
{
    return _isSigned;
}

int AForm::getGradeToExecute() const
{
    return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &b)
{
    if(this->_isSigned)
        throw AForm::AlreadySignedException() ;
    
    if(b.getGrade() > this->_gradeToSign)
    {
        throw AForm::GradeTooLowException();
    }
    this->_isSigned = true;
}

void AForm::execute(const Bureaucrat &executor) const
{
    if (!this->_isSigned)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->_gradeToExecute)
        throw AForm::GradeTooLowException();
    executeAction();
}

std::ostream &operator<<(std::ostream &os, const AForm &f)
{
    os << "Form Name: " << f.getName()
       << ", Signed: " << (f.getIsSigned() ? "Yes" : "No")
       << ", Grade to Sign: " << f.getGradeToSign()
       << ", Grade to Execute: " << f.getGradeToExecute();
    return os;
}
