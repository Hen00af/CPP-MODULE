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

        // try execute before signing
        std::cout << "--- Execute before signing ---" << std::endl;
        bob.executeForm(shrubbery);

        // sign and execute shrubbery
        std::cout << "\n--- ShrubberyCreationForm ---" << std::endl;
        std::cout << shrubbery << std::endl;
        bob.signForm(shrubbery);
        bob.executeForm(shrubbery);
        alice.executeForm(shrubbery);
        std::cout << shrubbery << std::endl;

        // sign and execute robotomy
        std::cout << "\n--- RobotomyRequestForm ---" << std::endl;
        std::cout << robotomy << std::endl;
        alice.signForm(robotomy);
        bob.executeForm(robotomy);
        alice.executeForm(robotomy);
        std::cout << robotomy << std::endl;

        // sign and execute presidential pardon
        std::cout << "\n--- PresidentialPardonForm ---" << std::endl;
        std::cout << pardon << std::endl;
        alice.signForm(pardon);
        bob.executeForm(pardon);
        alice.executeForm(pardon);
        std::cout << pardon << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}
