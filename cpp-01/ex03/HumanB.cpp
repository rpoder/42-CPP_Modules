/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:15:45 by ronanpoder        #+#    #+#             */
/*   Updated: 2022/12/04 18:03:43 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
	return ;
}

HumanB::~HumanB()
{
	return ;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

void	HumanB::attack(void)
{
	std::cout << this->_name;
	if (this->_weapon != NULL)
	{
		std::cout << " attacks with his "
		<< this->_weapon->getType()
		<< '.';
	}
	else
	{
		std::cout << " attacks.";
	}
	std::cout << std::endl;
}
