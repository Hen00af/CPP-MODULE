#include <iostream>
#include "animal.hpp"
#include "dog.hpp"
#include "cat.hpp"
#include "brain.hpp"

int main()
{
    const int N = 10;
    Animal* animals[N];

    for (int i = 0; i < N / 2; i++)
        animals[i] = new Dog();

    for (int i = N / 2; i < N; i++)
        animals[i] = new Cat();

    for (int i = 0; i < N; i++)
        delete animals[i];

    Dog basic;
    {
        Dog tmp = basic;
    }

    return 0;
}
