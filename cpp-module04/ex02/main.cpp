#include <iostream>
#include "animal.hpp"
#include "dog.hpp"
#include "cat.hpp"
#include "wronganimal.hpp"
#include "wrongcat.hpp"

int main()
{
    std::cout << "=== 1. basic polymofizm ===" << std::endl;
    {
        const Animal* dog = new Dog();
        const Animal* cat = new Cat();

        dog->makeSound();
        cat->makeSound();
    }

    std::cout << "=== 2. danger of WrongAnimal ===" << std::endl;
    {
        const WrongAnimal* wcat = new WrongCat();

        wcat->makeSound();
        // WrongCat makeSound will not be called
        delete wcat;
        // this will be leat coz Wrong cat destructor can`t be called
    }

    std::cout << "\n=== 3. DeepCopy Test===" << std::endl;
    {
        Dog basic;
        Dog tmp = basic;

        std::cout << "basic.brain   =" << basic.getBrain() << std::endl;
        std::cout << "tmp.brain   =" << tmp.getBrain() << std::endl;
    }

    std::cout << "\n=== 4. assignment operator Deep Copy (not necessary) ===" << std::endl;
    {
        Dog a;
        Dog b;
        b = a;

        std::cout << "a.brain   = " << a.getBrain() << std::endl;
        std::cout << "b.brain   = " << b.getBrain() << std::endl;
    }

    std::cout << "\n=== 5. memory leak check ===" << std::endl;
    {
        const int N = 10;
        Animal * animals[N];

        for(int i = 0; i < N / 2; i++)
            animals[i] = new Dog();
        for(int i = N/2; i < N; i++)
            animals[i] = new Cat();
        for(int i = 0; i < N; i++)
            delete animals[i];
    }

    std::cout << "\n=== 6. danger of delete polymophizm in WrongAnimal  ===" << std::endl;
    {
        WrongAnimal* arr[4] = {
            new WrongAnimal(),
            new WrongCat(),
            new WrongAnimal(),
            new WrongCat()
        };

        for(int i = 0; i < 4; i++)
            delete arr[i];
    }


    std::cout << "\n=== 8. Dog のコピー内で Brain が別物か検証 ===" << std::endl;
    {
        Dog d1;
        d1.getBrain()->setIdea(0, "I want meat!");

        Dog d2 = d1;

        std::cout << "d1 idea: " << d1.getBrain()->getIdea(0) << std::endl;
        std::cout << "d2 idea: " << d2.getBrain()->getIdea(0) << std::endl;

        d2.getBrain()->setIdea(0, "I want sleep!");
        std::cout << "After change:" << std::endl;

        std::cout << "d1 idea: " << d1.getBrain()->getIdea(0) << std::endl;
        std::cout << "d2 idea: " << d2.getBrain()->getIdea(0) << std::endl;

        // ✅ d1 と d2 が独立していれば Deep Copy 成功
    }

    std::cout << "\n=== 9. 問題があればクラッシュ・リークする部分 ===" << std::endl;
    {
        Dog* d = new Dog();
        Dog* dcopy = new Dog(*d);   // copy constructor
        delete d;
        delete dcopy;               // ✅ shallow copy だとここでクラッシュ
    }

    std::cout << "\n=== 10. WrongAnimal の音声比較 ===" << std::endl;
    {
        WrongAnimal* w1 = new WrongAnimal();
        WrongAnimal* w2 = new WrongCat();

        w1->makeSound(); // WrongAnimal sound
        w2->makeSound(); // ❌ WrongAnimal sound（間違い）

        delete w1;
        delete w2;
    }

    std::cout << "\n=== 全テスト完了 ===" << std::endl;

    return 0;
}
