#include <iostream>
#include "bureaucrat.hpp"

int main()
{
    try{
        Bureaucrat alice("alice", 1);
        std::cout << alice << std::endl;

        Bureaucrat bob("bob", 150);
        std::cout << bob << std::endl;

        bob.decrementGrade();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try{
        Bureaucrat charlie("charlie", 0);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}