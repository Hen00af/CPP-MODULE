#include <iostream>
#include "cat.hpp"
#include "dog.hpp"
#include "animal.hpp"

int main()
{
    std::cout << std::endl;
    std::cout << "-----Constructor is called-----" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << std::endl;
    std::cout << "-------getType test------" << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << std::endl;
    std::cout << "-------make sound test------" << std::endl;
    
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    std::cout << std::endl;
    std::cout << "-----Destructor is called-----" << std::endl;
    delete meta;
    delete j;
    delete i;
    std::cout << std::endl;
    return 0;
}
