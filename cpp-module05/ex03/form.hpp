#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        const int  _gradeToSign;
        const int  _gradeToExecute;
        bool _isSigned;
        virtual void executeAction() const = 0;

    public:
        AForm(const std::string &name, int gradeToSign, int gradeToExecute);
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);
        virtual ~AForm();

        void execute(const Bureaucrat &executor) const;

        const std::string &getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned(const Bureaucrat &b);
        
        class GradeTooHighException : public std::exception {
        public:
            const char *what() const throw() { return "Grade too high!"; }
        };
        class GradeTooLowException : public std::exception {
        public:
            const char *what() const throw() { return "Grade too low!"; }
        };
        class AlreadySignedException : public std::exception {
        public:
            const char* what() const throw() {
                return "Form already signed";
            }
        };
        class FormNotSignedException : public std::exception {
        public:
            const char* what() const throw() {
                return "Form is not signed";
            }
        };


};

std::ostream &operator<<(std::ostream &os, const AForm &f);

#endif