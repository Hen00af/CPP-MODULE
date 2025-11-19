#include "form.hpp"

Form::Form(const std::string &name,int gradeToSign, int gradeToExecute)
{
    this->_name = name;
    this->_gradeToSign = gradeToSign;
    this->_gradeToExecute = gradeToExecute;
    this->_isSigned = false;
}

Form::~Form()
{
}

int Form::getGradeToSign()
{
    return _gradeToSign;
}

const std::string Form::getName()
{
    return _name;
}

bool Form::getIsSigned() const
{
    return _isSigned;
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
    os << "Form Name: " << f.getName() << ", Signed: "
         << (f.getIsSigned() ? "Yes" : "No") << ", Grade to Sign: "
         << f.getGradeToSign() << ", Grade to Execute: " << f.getGradeToExecute();
    return os;
}
