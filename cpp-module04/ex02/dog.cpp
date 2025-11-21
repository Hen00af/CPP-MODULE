#include "dog.hpp"

Dog::Dog() : Animal() {
    std::cout << "Dog constructor called" << std::endl;
    _brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other) {
    std::cout << "Dog copy constructor called" << std::endl;
    _brain = new Brain(*other._brain); // ✅ deep copy
}

Dog& Dog::operator=(const Dog &other) {
    std::cout << "Dog operator= called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete _brain;
        _brain = new Brain(*other._brain); // ✅ deep copy
    }
    return *this;
}

Dog::~Dog() {
    delete _brain;
    std::cout << "Dog destructor called" << std::endl;
}

Brain* Dog::getBrain() const {
    return _brain;
}

std::string Dog::getType() const {
    return "Dog";
}

void Dog::makeSound() const {
    std::cout << "Woof!" << std::endl;
}
