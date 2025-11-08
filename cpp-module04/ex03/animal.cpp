#include "animal.hpp"

Animal::Animal()
{
    this->type = "Animal";
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &other)
{
    this->type = other.type;
    std::cout << "Animal copy constructor called named " << other.getType() << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const {
    return this->type;
}

void Animal::makeSound() const {
    std::cout << "<generic animal sound>" << std::endl;
}
