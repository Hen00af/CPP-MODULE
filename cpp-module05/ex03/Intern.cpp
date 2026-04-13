#include "Intern.hpp"
#include "form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {
    std::cout << "constructor is called" << std::endl;
}

Intern::Intern(const Intern &other) {
    (void)other;
}

Intern::~Intern() {
    std::cout << "destructor is called" << std::endl;
}

const Intern &Intern::operator=(const Intern &other) {
    (void)other;
    return *this;
}
    /*
        listで保持したテンプレと照合したら、それに紐ずく関数を呼び出す。
        if/elseは美しくないらしいのでswitch/caseで
    */
AForm *Intern::makeForm(std::string formName, std::string target) {

    std::string list[] =  {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    for (int i = 0; i < 3; ++i) {
        if (formName == list[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            switch(i){
                case 0: return new ShrubberyCreationForm(target);
                case 1: return new RobotomyRequestForm(target);
                case 2: return new PresidentialPardonForm(target);
            }
        }
    }

    std::cout << "Error: Form name '" << formName << "' doesn't exist." << std::endl;
    return NULL;
}
