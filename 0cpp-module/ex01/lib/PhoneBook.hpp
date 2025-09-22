/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 20:32:08 by shattori          #+#    #+#             */
/*   Updated: 2025/09/22 15:47:38 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <string>
#include <iostream>
#include "Contact.hpp"

class phonebook {
private:
Contact contacts[7];
    int     _index;
    int     _total;
    char     *_contacts;
	
public:
    phonebook(void);
    ~phonebook(void);

    void add(void);
    void search(void);
    void print(const Contact& contact);
};

#endif
