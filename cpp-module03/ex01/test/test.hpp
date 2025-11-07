#pragma once
#define TEST_HPP
#include <iostream>

class parent{
    public:
    void hello() { std::cout << "Parent!" << std::endl; }
};

class child : public parent{
    public:
    void hello() { std::cout << "Child!" << std::endl; }
};