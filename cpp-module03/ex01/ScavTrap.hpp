/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 20:58:16 by shattori          #+#    #+#             */
/*   Updated: 2025/11/06 20:58:19 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _ScavTrap_HPP
#define _ScavTrap_HPP

void guardGate();

class ClapTrap: public ScavTrap{
    public:
    void    guardGate();
};

#endif
