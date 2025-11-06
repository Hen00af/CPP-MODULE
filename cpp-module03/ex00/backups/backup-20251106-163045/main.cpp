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

int main()
{
	ClapTrap ct("hoge");

	cp.attack("Enemy");
	cp.takeDamage(10);
	cp.attack("Enemy");
	cp.beRepaired(10);
	cp.takeDamage(10);
	cp.beRepaired(5);
	return 0;
}

