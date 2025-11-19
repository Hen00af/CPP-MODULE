#include "bureaucrat.hpp"
#include "form.hpp"

int main() {
    try {
        Bureaucrat alice("Alice", 50);
        Bureaucrat bob("Bob", 100);

        Form contract("Contract", 75, 50);

        std::cout << contract << std::endl;

        bob.signForm(contract);
        alice.signForm(contract);

        std::cout << contract << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

