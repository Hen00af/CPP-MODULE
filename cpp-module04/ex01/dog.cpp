#include "dog.hpp"

Dog::Dog()
    : Animal()
{
    std::cout << "Dog default constructor called" << std::endl;
    _brain = new Brain();
}

Dog::Dog(const Dog &other)
    : Animal(other)
{
    std::cout << "Dog copy constructor called" << std::endl;
    _brain = new Brain(*other._brain);
}

Dog::~Dog()
{
    delete _brain;
    std::cout << "Dog destructor called" << std::endl;
}

std::string Dog::getType() const {
    return "Dog";
}

void Dog::makeSound() const {
    std::cout << "Woof Woof🐶" << std::endl;
}
