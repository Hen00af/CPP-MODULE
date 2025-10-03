#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type)
{}

Weapon::~Weapon()
{
	std::cout << "Weapon destructor called" << std::endl;
}
