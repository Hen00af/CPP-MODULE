/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 20:30:53 by shattori          #+#    #+#             */
/*   Updated: 2025/10/02 01:41:12 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include <algorithm> 
#include <cctype>
#define TRUE 	1
#define FALSE 	0

int main()
{
	std::string input;
	PhoneBook pb1;
	
	std::cout << "Welcome to PhoneBook!" << std::endl;
	std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;
	
	while(true)
	{
		std::cout << "PhoneBook> ";
		if (!std::getline(std::cin, input))
		{
			std::cout << std::endl << "EOF detected. Exiting..." << std::endl;
			return 0;
		}
		// Convert input to uppercase (C++98 compatible way)
		for (size_t i = 0; i < input.length(); ++i) {
			input[i] = std::toupper(input[i]);
		}
        if (input == "EXIT")
        {
            std::cout << "Goodbye!" << std::endl;
            break;
        }
        else if (input == "ADD"){
            if(pb1.add() == FALSE)
				break;
		}
        else if (input == "SEARCH"){
            if(pb1.search() == FALSE)
				break;
		}
        else
            std::cout << "Invalid command. Use ADD, SEARCH, or EXIT." << std::endl;
	}
	return(0);
}
