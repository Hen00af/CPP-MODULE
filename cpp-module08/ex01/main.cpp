#include <iostream>
#include <vector>
#include <cstdlib>
#include "Span.hpp"

int main(void)
{
	// Subject test
	std::cout << "=== Subject test ===" << std::endl;
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	// Overflow test
	std::cout << "=== Overflow test ===" << std::endl;
	try
	{
		sp.addNumber(42);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	// Too few elements test
	std::cout << "=== Too few elements test ===" << std::endl;
	Span sp2(1);
	sp2.addNumber(1);
	try
	{
		sp2.shortestSpan();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	// Large test (10000 numbers)
	std::cout << "=== 10000 numbers test ===" << std::endl;
	Span big(10000);
	srand(42);
	for (int i = 0; i < 10000; i++)
		big.addNumber(rand());
	std::cout << "shortest: " << big.shortestSpan() << std::endl;
	std::cout << "longest: " << big.longestSpan() << std::endl;

	// Range insert test
	std::cout << "=== Range insert test ===" << std::endl;
	Span sp3(5);
	std::vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	sp3.addRange(v.begin(), v.end());
	std::cout << "shortest: " << sp3.shortestSpan() << std::endl;
	std::cout << "longest: " << sp3.longestSpan() << std::endl;

	// Range overflow test
	std::cout << "=== Range overflow test ===" << std::endl;
	Span sp4(3);
	try
	{
		sp4.addRange(v.begin(), v.end());
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
