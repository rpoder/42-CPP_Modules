/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ronanpoder <ronanpoder@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:40:57 by ronanpoder        #+#    #+#             */
/*   Updated: 2022/11/15 20:56:07 by ronanpoder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string weapon) : _type(weapon)
{
	return;
}

Weapon::~Weapon()
{
	return;
}

std::string	const &Weapon::getType() const
{
	return (this->_type);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}
