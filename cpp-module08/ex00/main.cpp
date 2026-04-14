#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main(void)
{
	// Test with vector
	std::cout << "=== vector ===" << std::endl;
	std::vector<int> vec;
	for (int i = 0; i < 10; i++)
		vec.push_back(i * 3);

	try
	{
		std::vector<int>::iterator it = easyfind(vec, 9);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		easyfind(vec, 42);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	// Test with list
	std::cout << "=== list ===" << std::endl;
	std::list<int> lst;
	for (int i = 0; i < 5; i++)
		lst.push_back(i + 10);

	try
	{
		std::list<int>::iterator it = easyfind(lst, 12);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	// Test with deque
	std::cout << "=== deque ===" << std::endl;
	std::deque<int> deq;
	deq.push_back(100);
	deq.push_back(200);
	deq.push_back(300);

	try
	{
		std::deque<int>::iterator it = easyfind(deq, 200);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
