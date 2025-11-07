#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
    : ClapTrap()
{
    std::cout << "ScavTrap constructor is called" << std::endl;

    // 親クラスのprotectedメンバにアクセスして初期化
    _hit_points = 100;
    _energy_points = 50;
    _attack_damage = 50;
}

ScavTrap::ScavTrap(std::string name)
    : ClapTrap(name)
{
    std::cout << "ScavTrap default constructor called: " << name  << std::endl;
    // overwrite base defaults

    _hit_points = 100;
    _energy_points = 50;
    _attack_damage = 20;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called:" << _name << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gate keeper mode!" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    std::cout << "ScavTrap " << _name << " ";
    if (_hit_points == 0)
        std::cout << "is already dead...";
    else if (_energy_points == 0)
        std::cout << "has no more energy points...";
    else
    {
        std::cout << "attacks " << target << ", causing " << _attack_damage << " points of damage.";
        --_energy_points;
    }
    std::cout << std::endl;
}

