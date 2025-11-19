#include <iostream>
#include <string>
#include <stdexcept>
#include "bureaucrat.hpp"

int main(int ac, char** av)
{
    try {
        if (ac >= 3) {

            std::string name = av[1];
            int grade = 0;

            try {
                grade = std::stoi(av[2]); 
            } catch (const std::invalid_argument&) {
                std::cerr << "Error: grade must be a number." << std::endl;
                return 1;
            } catch (const std::out_of_range&) {
                std::cerr << "Error: grade value out of range." << std::endl;
                return 1;
            }

            Bureaucrat person(name, grade);
            std::cout << person << std::endl;
            return 0;
        }

        // === テストモード ===
        if (ac == 1) {
            std::cout << "=== test mode ===" << std::endl;

            Bureaucrat alice("alice", 1);
            std::cout << alice << std::endl;

            Bureaucrat bob("bob", 150);
            std::cout << bob << std::endl;

            try {
                bob.decrementGrade();
            } catch (const std::exception& e) {
                std::cerr << e.what() << std::endl;
            }

            try {
                Bureaucrat charlie("charlie", 0);
            } catch (const std::exception& e) {
                std::cerr << e.what() << std::endl;
            }
            return 0;
        }

        // === 引数不正 ===
        std::cerr << "Usage: " << av[0] << " <name> <grade>" << std::endl;
        return 1;

    } catch (const std::exception& e) {
        std::cerr << "Fatal error: " << e.what() << std::endl;
        return 1;
    }
}
