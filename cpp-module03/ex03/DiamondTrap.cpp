#include <iostream>
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
    : ClapTrap("default_clap_name"), FragTrap(), ScavTrap(), _name("default")
{
    std::cout << "DiamondTrap default constructor called" << std::endl;
    // DiamondTrap uses FragTrap's hit points, ScavTrap's energy, FragTrap's attack
    _hit_points = 100; // from FragTrap
    _energy_points = 50; // from ScavTrap
    _attack_damage = 30; // from FragTrap
}

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name)
{
    std::cout << "DiamondTrap constructor called: " << name << std::endl;
    _hit_points = 100; // FragTrap
    _energy_points = 50; // ScavTrap
    _attack_damage = 30; // FragTrap
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called: " << _name << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
    // Use ScavTrap's attack implementation
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "I am " << _name << ", ClapTrap name: " << ClapTrap::_name << std::endl;
}
