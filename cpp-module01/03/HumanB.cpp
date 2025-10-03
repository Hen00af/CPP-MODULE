#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL)
{}

HumanB::~HumanB()
{
	std::cout << "HumanB destructor called" << std::endl;
}
