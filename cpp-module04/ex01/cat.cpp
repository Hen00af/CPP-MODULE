#include "cat.hpp"
#include <iostream>
    
Cat::Cat()
    : Animal() {
        std::cout << "Cat default constructor called" << std::endl;
    _brain = new Brain();
}
Cat::Cat(const Cat &other)
    : Animal(other) {
        std::cout << "Cat copy constructor called" << std::endl;
        _brain = new Brain(*other._brain);
    }
Cat::~Cat() {
    delete _brain;
    std::cout << "Cat destructor called" << std::endl;
}
std::string Cat::getType() const {
    return "Cat";
}
void Cat::makeSound() const {
    std::cout << "Meow Meow🐱" << std::endl;
}
