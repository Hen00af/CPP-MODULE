#include "wrongcat.hpp"
#include <iostream>

WrongCat::WrongCat()
    : WrongAnimal()
{
    this->type = "WrongCat";
    std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other)
    : WrongAnimal(other)
{
    this->type = other.type;
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}

std::string WrongCat::getType() const {
    return this->type;
}

void WrongCat::makeSound() const {
    std::cout << "Wrong Meow" << std::endl;
}
