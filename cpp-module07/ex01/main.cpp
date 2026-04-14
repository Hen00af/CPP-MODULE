#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void print(T const &x)
{
	std::cout << x << std::endl;
}

void increment(int &x)
{
	x++;
}

int main(void)
{
	int intArray[] = {1, 2, 3, 4, 5};
	std::cout << "=== int array ===" << std::endl;
	iter(intArray, 5, print<int>);

	std::cout << "=== after increment ===" << std::endl;
	iter(intArray, 5, increment);
	iter(intArray, 5, print<int>);

	std::string strArray[] = {"Hello", "World", "42", "Tokyo"};
	std::cout << "=== string array ===" << std::endl;
	iter(strArray, 4, print<std::string>);

	double dblArray[] = {1.1, 2.2, 3.3};
	std::cout << "=== double array ===" << std::endl;
	iter(dblArray, 3, print<double>);

	return 0;
}
