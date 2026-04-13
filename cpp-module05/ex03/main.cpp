#include "bureaucrat.hpp"
#include "form.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void test_output(std::string out) {
    std::cout << "=======================" << out << "=======================" << std::endl;
}

int main() {

    test_output("start");

    Bureaucrat alice("Alice", 1);
    
    
    Intern someRandomIntern;
    AForm*  rrf;

    test_output("robotomy request");

    try {
        rrf = someRandomIntern.makeForm("robotomy request", "test1");
        alice.signForm(*rrf);
        alice.executeForm(*rrf);
        delete rrf;
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        delete rrf;
    }

    test_output("shrubbery creation");

    try {
        rrf = someRandomIntern.makeForm("shrubbery creation", "test2");
        alice.signForm(*rrf);
        alice.executeForm(*rrf);
        delete rrf;
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        delete rrf;
    }


    test_output("presidential pardon");

    try {
        rrf = someRandomIntern.makeForm("presidential pardon", "test3");
        alice.signForm(*rrf);
        alice.executeForm(*rrf);
        delete rrf;
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        delete rrf;
    }

    test_output("finish");


}
