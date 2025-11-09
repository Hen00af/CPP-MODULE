#include <iostream>
#include "animal.hpp"
#include "dog.hpp"
#include "cat.hpp"
#include "wronganimal.hpp"
#include "wrongcat.hpp"

int main()
{
    std::cout << "\n --------test start -------- \n";
    std::cout << "\n --------constractor test with no danger-------- \n";
    {
        Animal *animal = new Animal;
        WrongAnimal *wanimal;
        
        wanimal = new WrongAnimal;
        std::cout << "\n --------destractor-------- \n";
        delete animal;
        delete wanimal;
        std::cout << "\n --------constractor test with danger-------- \n";
        Animal _animal;
        WrongAnimal _wanimal;
    }

    return 0;
}
