#pragma once
#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>
#include <string>

class Animal{
    public:
        Animal();
        Animal(const Animal &other);
        // Animalの子クラスのデストラクタが正しい順序で
        // 呼び出されるようにするために仮想デストラクタにする
        virtual ~Animal();
        virtual std::string getType() const;
        virtual void makeSound() const;
    protected:
        std::string type;
};

#endif
