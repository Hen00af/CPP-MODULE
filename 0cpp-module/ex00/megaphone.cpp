/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:56:08 by shattori          #+#    #+#             */
/*   Updated: 2025/08/05 20:29:11 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main (int ac , char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		for(int i = 1 ;i < ac; i++)
		{
			for(int j = 0; av[i][j] != '\0'; j++)
			{
				std::cout << (char)toupper(av[i][j]);
			}
		}
		std::cout << std::endl;
	}
	return (0);
}
