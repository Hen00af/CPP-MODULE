/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 09:27:13 by shattori          #+#    #+#             */
/*   Updated: 2025/09/24 15:51:36 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::setField(int index, const std::string &value)
{
	switch(index){
		case 0: _firstName = value; break;
		case 1: _lastName = value; break;
		case 2: _nickname = value; break;
		case 3: _phoneNumber = value; break;
		case 4: _darkestSecret = value; break;
		default: break;
		}
}

const std::string &Contact::getField(int index) const{
	static const std::string empty = "";
	switch (index){
		case 0: return _firstName;
		case 1: return _lastName;
		case 2: return _nickname;
		case 3: return _phoneNumber;
		case 4: return _darkestSecret;
		default: return empty;
	}
}
