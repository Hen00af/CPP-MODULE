/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 21:00:00 by shattori          #+#    #+#             */
/*   Updated: 2025/11/07 21:00:00 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <string>

class DiamondTrap : public FragTrap, public ScavTrap {
private:
    // Must have the same variable name as ClapTrap's name member (here: _name)
    std::string _name;
public:
    DiamondTrap();
    DiamondTrap(std::string name);
    ~DiamondTrap();

    void attack(const std::string &target);
    void whoAmI();
};

#endif
