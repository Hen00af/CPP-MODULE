#ifndef INTERN_HPP
#define INTERN_HPP

#include "form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
    public:
        Intern();
        Intern(const Intern &other);
        ~Intern();
        const Intern &operator=(const Intern &other);

       AForm *makeForm(std::string FormName, std::string target);
        
    private:
};

#endif