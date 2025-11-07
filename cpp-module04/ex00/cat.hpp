#pragma once
#ifndef CAT_HPP
#define CAT_HPP
#include <iostream>
#include "animal.hpp"

class Cat : public Animal {
    public:
        Cat();
        ~Cat();
        Cat(const Cat &other);

        //
        std::string getType() const;
        void makeSound() const;
    private:
};

#endif
