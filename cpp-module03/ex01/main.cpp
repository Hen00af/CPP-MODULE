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

int main()
{
    std::cout << "=== ClapTrap basic test ===" << std::endl;
    {
        ClapTrap ct("Clappy");
        ct.attack("Enemy A");
        ct.takeDamage(5);
        ct.beRepaired(3);
        ct.takeDamage(10);
    } // ここで ClapTrap のデストラクタが呼ばれる

    std::cout << "\n=== ScavTrap inheritance test ===" << std::endl;
    {
        ScavTrap st("Scavvy");
        st.attack("Enemy B");       // ScavTrap版 attack()
        st.takeDamage(20);
        st.beRepaired(10);
        st.guardGate();             // ScavTrap 特有の機能
        st.takeDamage(100);         // HP を 0 にしてみる
        st.attack("Enemy C");       // 攻撃できないことを確認
    } // ここで ScavTrap → ClapTrap の順にデストラクタが呼ばれる

    std::cout << "\n=== Polymorphism test (optional) ===" << std::endl;
    {
        ClapTrap *p = new ScavTrap("PolyScav");
        p->attack("Enemy D");    // 仮想関数でないため ClapTrap::attack() が呼ばれる（仕様確認）
        delete p;
    }

    return 0;
}
