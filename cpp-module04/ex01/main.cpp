#include <iostream>
#include "animal.hpp"
#include "dog.hpp"
#include "cat.hpp"
#include "brain.hpp"

int main()
{
    const int N = 10;
    Animal* animals[N];

    std::cout << "\n====Dog constructor called====\n" << std::endl;
    for (int i = 0; i < N / 2; i++)
        animals[i] = new Dog();

    std::cout << "\n====Cat constructor called====\n" << std::endl;
    for (int i = N / 2; i < N; i++)
        animals[i] = new Cat();

    std::cout << "\n====Destructor called====\n" << std::endl;
    for (int i = 0; i < N; i++)
        delete animals[i];

    std::cout << "\n====Deep copy test====\n" << std::endl;
    Dog basic;
    {
        Dog tmp = basic;
    }

    return 0;
}
