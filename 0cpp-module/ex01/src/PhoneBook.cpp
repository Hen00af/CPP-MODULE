/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 02:15:19 by shattori          #+#    #+#             */
/*   Updated: 2025/09/22 13:42:32by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string add()
{
	int cnt;
	char *ask[]={
		"first name",
		"last name",
		"nickname",
		"phone number",
		"darkest secret"
	};
	ContactInfo contacts;
	std::string input;
	for(int i = 0;i < 5; ++i)
	{
		std::cout << "please type " << ask[i] << ": ";
		std::getline(std::cin, input);

		switch (i){
			case 0: contacts.first_name = input; break;
			case 1: contacts.last_name  = input; break;
			case 2: contacts.nick		= input; break;
			case 3: contacts.phone_num 	= input; break;
			case 4: contacts.secret		= input; break;
		}
	}
	return contacts;
}
