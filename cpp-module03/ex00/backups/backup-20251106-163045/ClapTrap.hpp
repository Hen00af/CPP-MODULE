/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:43:28 by shattori          #+#    #+#             */
/*   Updated: 2025/11/06 11:57:23 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifnef ClapTrap_HPP
#define	ClapTrap_HPP

#include <string>

Class ClapTrap{
private:
	std::string _name;
	unsigned int _hit_potint;
	unsigned int _energy_point;
	unsigned int _Attack_point;

	ClapTrap(std::string const &name, unsigned int hit_points,
			unsigned int energy_points, unsigned int attack_damage);

public:
	static unsigned int const default_hit_points;
	static unsigned int const default_energy_points;
	static unsigned int const default_attack_damege;
	
	ClapTrap(std::string const &name = "");
	
	void attack(const std::string& target);
	void takeDamage(unsigned int amount;
	void beRepaired(unsigned int amount);
}
