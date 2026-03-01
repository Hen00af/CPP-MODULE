#include <iostream>
#include "bureaucrat.hpp"

int main()
{
    try{
        std::cout << "alice" << std::endl;
        Bureaucrat alice("alice", 1);
        std::cout << alice << std::endl;

        std::cout << "bob" << std::endl;
        Bureaucrat bob("bob", 150);
        std::cout << bob << std::endl;

        bob.decrementGrade();
        std::cout << bob << std::endl;
        bob.incrementGrade();
        std::cout << bob << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try{
        std::cout << "charlie" << std::endl;
        Bureaucrat charlie("charlie", 0);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}