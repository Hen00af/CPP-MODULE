/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 20:30:53 by shattori          #+#    #+#             */
/*   Updated: 2025/09/22 13:56:30 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <algorithm> 

int main()
{
	std::string input;
	phonebook pb1;
	
	while(true)
	{
		std::cout << ">";
		if (!std::getline(std::cin, input))
		{
			std::cout << "next\n";
			return 0;
		}
		std::transform(
			input.begin(),
			input.end(),
			input.begin(),
			[](unsigned char c)
			{return static_cast<char>(std::toupper(c));}
		);
		const char *str = input.c_str();
        if (str == "EXIT")
        {
            std::cout << "exit" << std::endl;
            break;
        }
        else if (str == "ADD")
            pb1.add();
        else if (str == "SEARCH")
            pb1.search();
        else
            std::cout << "this can exec" << std::endl;
	}
	return(0);
}
