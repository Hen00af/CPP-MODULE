#pragma once
#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <iostream>
#include <string>
#include "brain.hpp"

class WrongAnimal{
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal &other);
        virtual ~WrongAnimal();

        std::string getType() const;
        void makeSound() const;
        Brain* getBrain() const;
    protected:
        std::string type;
        Brain *_brain;
};

#endif
