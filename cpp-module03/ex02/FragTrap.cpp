#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap()
    : ClapTrap()
{
    std::cout << "FragTrap constructor called" << std::endl;
    _hit_points = 100;
    _energy_points = 100;
    _attack_damage = 30;
}

FragTrap::FragTrap(std::string name)
    : ClapTrap(name)
{
    std::cout << "FragTrap constructor called: " << name << std::endl;
    _hit_points = 100;
    _energy_points = 100;
    _attack_damage = 30;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called: " << _name << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << _name << " requests a positive high five!" << std::endl;
}
