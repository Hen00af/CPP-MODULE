/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:46:32 by shattori          #+#    #+#             */
/*   Updated: 2025/11/06 16:30:45 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

const unsigned int ClapTrap::default_hit_points = 10;
const unsigned int ClapTrap::default_energy_points = 10;
const unsigned int ClapTrap::default_attack_damage = 0;


ClapTrap::ClapTrap(std::string const &name)
	: _name(name), _hit_points(default_hit_points), _energy_points(default_energy_points), _attack_damage(default_attack_damage)
{
	std::cout << "ClapTrap default constructor called: " << _name << std::endl;
	is_dead = true;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called: " << _name << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	std::cout << "ClapTrap " << _name << " ";
	if(is_dead)
		std::cout << _name << "... is already died ..." << std::endl;
	else if (_hit_points == 0)
		std::cout << " ... is already dead...";
	else if (_energy_points == 0)
		std::cout << "has no more energy points...";
	else
	{
		std::cout << "attacks " << target << ", causing " << _attack_damage << " points of damage.";
		--_energy_points;
	}
	std::cout << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << " ";
	if (_hit_points == 0 || is_dead)
	{
		std::cout << " ... is already dead..." << std::endl;
		return;
	}
	if (_hit_points > amount)
	{
		_hit_points -= amount;
		std::cout << "takes " << amount << " points of damage, remaining HP: " << _hit_points << std::endl;
	}
	else
	{
		_hit_points = 0;
		std::cout << "takes " << amount << " points of damage, and died..." << std::endl;
		this->is_dead = true;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << " ";
	if(is_dead)
		std::cout << _name << " ... is already died ..." << std::endl;
	else if (_energy_points == 0)
	{
		std::cout << "has no more energy to repair..." << std::endl;
		return;
	}
	_hit_points += amount;
	--_energy_points;
	std::cout << "is repaired by " << amount << " points, HP: " << _hit_points << ", Energy: " << _energy_points << std::endl;
}
