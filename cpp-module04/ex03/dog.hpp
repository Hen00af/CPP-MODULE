#pragma once
#ifndef DOG_HPP
#define DOG_HPP
#include <iostream>
#include "animal.hpp"
#include "brain.hpp"

class Dog : public Animal {
    public:
        Dog();
        Dog(const Dog &other);
        ~Dog();
        //
        std::string getType() const;
        void makeSound() const;
    private:
        Brain* _brain;
};

#endif
