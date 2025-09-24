/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 20:32:08 by shattori          #+#    #+#             */
/*   Updated: 2025/09/24 15:06:23 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <string>
#include <iostream>
#include "Contact.hpp"

class PhoneBook{
private:
    Contact contacts[8];  // 8個の連絡先
    int     _index;
    int     _total;
public:
    PhoneBook();
    ~PhoneBook(void);
    void add(void);
    void search(void);
    void print(const Contact& contact);
};

#endif
