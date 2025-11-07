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
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
protected:
	std::string _name;
	unsigned int _hit_points;
	unsigned int _energy_points;
	unsigned int _attack_damage;

	ClapTrap(std::string const &name, unsigned int hit_points,
			unsigned int energy_points, unsigned int attack_damage);

public:
	static const unsigned int default_hit_points;
	static const unsigned int default_energy_points;
	static const unsigned int default_attack_damage;

	ClapTrap(std::string const &name = "");
	~ClapTrap();

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif
