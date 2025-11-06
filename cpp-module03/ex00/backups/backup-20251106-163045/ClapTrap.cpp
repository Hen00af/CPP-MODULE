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

unsigned int const ClapTrap::default_hit_points = 10;
unsigned int const ClapTrap::def

ClapTrap::ClapTrap(std::string const &name, unsigned int hit_points,
				unsigned int energy_points, unsigned int attack_damege){
	std::cout << "ClapTrap private constractor called" << _name << std::endl;
}

ClapTrap::ClapTrap() {
	std::cout << "ClapTrap default constractor called " << _name << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap deconstructor called" << std::endl;
}

//attack
void attack(std::string const &target)
{
	std::cout << "ClapTrap " << _name << " ";
	if (!_hit_points)
		std::cout << "already dead...";
	else if (!_energy_points)
		std::cout << "no more energy points...";
	else{
		std::cout << "attacks " << target ;
		std::cout << "causing " << _attack_damage << " points of damage.";
		_enrgy_points --;
	}
	std::cout << std::endl;
}

// take damege
void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << " " ;

	if (!_hit_point)
		std::cout << "is already died ..." << std::endl;
	else{
		if(_hit_point > amount){
			std::cout << "takes" << endl;
			this->_hit_point -= amount;
		else{
			std::cout << ", and died...";
			_hit_points = 0;	
		}
	}
}


//beRepaired
void	ClapTrap::beRepaired(unsigned int )
