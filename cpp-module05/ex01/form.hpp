#pragma once
#define FORM_HPP

#include "bureaucrat.hpp"
#include <iostream>
class Form
{
    private:
        std::string _name;
        int  _gradeToSign;
        int  _gradeToExecute;
        bool _isSigned;
    public:
        Form(std::string &name,int gradeToSign, int gradeToExecute);
        ~Form();

        const std::string getName();
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned(const Bureaucrat &b);
        
        class GradeTooHighException : public std::exception {
        const char *what() const throw() { return "Grade too high!"; }
        };
        class GradeTooLowException : public std::exception {
        const char *what() const throw() { return "Grade too low!"; }
        };
        
};

std::ostream &operator<<(std::ostream &os, const Form &f);