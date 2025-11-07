/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:43:54 by shattori          #+#    #+#             */
/*   Updated: 2025/11/06 11:46:02 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    std::cout << "===== DiamondTrap Test =====" << std::endl;

    DiamondTrap dt("dia");

    std::cout << "\n--- Attack Test (uses ScavTrap::attack) ---" << std::endl;
    dt.attack("enemy");

    std::cout << "\n--- Take Damage / Repair Test ---" << std::endl;
    dt.takeDamage(20);
    dt.beRepaired(10);

    std::cout << "\n--- FragTrap Ability Test ---" << std::endl;
    dt.highFivesGuys();

    std::cout << "\n--- DiamondTrap Ability Test ---" << std::endl;
    dt.whoAmI();

    std::cout << "\n--- Kill Test ---" << std::endl;
    dt.takeDamage(200);   // 死亡
    dt.attack("dead target"); // 死後行動不可チェック

    std::cout << "\n===== End =====" << std::endl;
    return 0;
}
