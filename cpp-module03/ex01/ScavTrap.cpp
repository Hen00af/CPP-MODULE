#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
    : ClapTrap()
{
    std::cout << "ScavTrap constructor is called";

    // 親クラスのprotectedメンバにアクセスして初期化
    //protected ... 子クラスでも親クラスでもアクセスできるソースのこと
    hitPoints = 100;
    energy_points = 50;
    attack_damage = 50;
}

ScavTrap::ScavTrap()
    :


ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor is called";
}

ScavTrap::guardgate()
{

}

