#pragma once
#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "wronganimal.hpp"
#include <string>

class WrongCat : public WrongAnimal {
    public:
        WrongCat();
        WrongCat(const WrongCat &other);
        ~WrongCat();
        std::string getType() const;
        void makeSound() const;

        Brain* getBrain() const;
    private:
        Brain* _brain;
};

#endif
