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

int main()
{
    std::cout << "-----ClapTrap------" << std::endl;
	ClapTrap ct("c");
    ct.attack("enermy");
    ct.takeDamage(100);
    std::cout << "-----ScavTrap------" << std::endl;
    ScavTrap st("s");
    std::cout << "-----FragTrap------" << std::endl;
    FragTrap ft("f");
    std::cout << "-----Destractor------" << std::endl;
	return 0;
}

