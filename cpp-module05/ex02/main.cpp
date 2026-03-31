#include "bureaucrat.hpp"
#include "form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat alice("Alice", 1);
        Bureaucrat bob("Bob", 100);

        ShrubberyCreationForm shrubbery("garden");
        RobotomyRequestForm robotomy("target");
        PresidentialPardonForm pardon("Zaphod");

        std::cout << shrubbery << std::endl;
        bob.signForm(shrubbery);
        alice.signForm(shrubbery);
        std::cout << shrubbery << std::endl;

        std::cout << robotomy << std::endl;
        alice.signForm(robotomy);
        std::cout << robotomy << std::endl;

        std::cout << pardon << std::endl;
        alice.signForm(pardon);
        std::cout << pardon << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

