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
    std::cout << "ScavTrap constructor for " << name << " called" << std::endl;
    // overwrite base defaults

    _hit_points = 100;
    _energy_points = 50;
    _attack_damage = 20;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor is called" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gate keeper mode!" << std::endl;
}

