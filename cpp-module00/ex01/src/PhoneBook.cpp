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
#include <iomanip>
#include <sstream>
#define TRUE 	1
#define FALSE 	0

PhoneBook::PhoneBook() : _index(0), _total(0){
}

PhoneBook::~PhoneBook() {
}

int PhoneBook::add() {
	std::string fields[5] = {
		"first name",
		"last name", 
		"nickname",
		"phone number",
		"darkest secret"
	};
	
	Contact newContact;
	std::string input;
	
	for(int i = 0; i < 5; ++i) {
		do {
			std::cout << "Enter " << fields[i] << ": ";
			if(!std::getline(std::cin, input)){
				std::cout << std::endl << "EOF detected. Exiting..." << std::endl;
				return (FALSE);
			}
			if (input.empty()) {
				std::cout << "Field cannot be empty. Please try again." << std::endl;
			}
		} while (input.empty());
		
		newContact.setField(i, input);
	}
	
	contacts[_index] = newContact;
	_index = (_index + 1) % 8;
	if (_total < 8) {
		_total++;
	}
	
	std::cout << "Contact added successfully!" << std::endl;
	return (TRUE);
}

int PhoneBook::search() {
	if (_total == 0) {
		std::cout << "Phonebook is empty!" << std::endl;
		return TRUE;
	}
	
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	
	for (int i = 0; i < _total; ++i) {
		std::cout << std::setw(10) << i << "|";
		
		std::string firstName = contacts[i].getField(0);
		if (firstName.length() > 10) {
			firstName = firstName.substr(0, 9) + ".";
		}
		std::cout << std::setw(10) << firstName << "|";
		
		std::string lastName = contacts[i].getField(1);
		if (lastName.length() > 10) {
			lastName = lastName.substr(0, 9) + ".";
		}
		std::cout << std::setw(10) << lastName << "|";
		
		std::string nickname = contacts[i].getField(2);
		if (nickname.length() > 10) {
			nickname = nickname.substr(0, 9) + ".";
		}
		std::cout << std::setw(10) << nickname << std::endl;
	}
	
	std::string indexStr;
	int selectedIndex;	
	do {
		std::cout << "Enter the index of the contact to display: ";
		if (!std::getline(std::cin, indexStr)){
				std::cout << std::endl << "EOF detected. Exiting..." << std::endl;
				std::cin.clear();
				return (FALSE);
		}
		std::stringstream ss(indexStr);
		if (!(ss >> selectedIndex) || selectedIndex < 0 || selectedIndex >= _total) {
			std::cout << "Invalid index. Please enter a number between 0 and " 
					  << (_total - 1) << std::endl;
			continue;
		}
		break;
	} while (true);
	print(contacts[selectedIndex]);
	return (TRUE);
}

void PhoneBook::print(const Contact& contact) {
	std::cout << std::endl << "=== Contact Details ===" << std::endl;
	std::cout << "First Name: " << contact.getField(0) << std::endl;
	std::cout << "Last Name: " << contact.getField(1) << std::endl;
	std::cout << "Nickname: " << contact.getField(2) << std::endl;
	std::cout << "Phone Number: " << contact.getField(3) << std::endl;
	std::cout << "Darkest Secret: " << contact.getField(4) << std::endl;
	std::cout << "========================" << std::endl << std::endl;
}
