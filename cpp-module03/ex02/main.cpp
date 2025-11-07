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

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << "=== ClapTrap test ===" << std::endl;
    {
        ClapTrap ct("Clappy");
        ct.attack("Enemy A");
        ct.takeDamage(5);
        ct.beRepaired(3);
        ct.takeDamage(10);
    } // destructor test


    std::cout << "\n=== ScavTrap test ===" << std::endl;
    {
        ScavTrap st("Scavvy");
        st.attack("Enemy B");       // ScavTrap 攻撃
        st.takeDamage(20);
        st.beRepaired(10);
        st.guardGate();             // ScavTrap 固有
        st.takeDamage(100);
        st.attack("Enemy C");       // HP 0 → 攻撃できない
    }


    std::cout << "\n=== FragTrap test ===" << std::endl;
    {
        FragTrap ft("Fraggy");
        ft.attack("Enemy X");       // FragTrap 攻撃（強い）
        ft.highFivesGuys();         // FragTrap 固有
        ft.takeDamage(50);
        ft.beRepaired(25);
        ft.takeDamage(200);         // 完全に死亡
        ft.attack("Enemy Y");       // HP 0 → 攻撃不可
        ft.highFivesGuys();         // 高速で呼んでも問題ないかチェック
    }

    return 0;
}
