/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ronanpoder <ronanpoder@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:40:57 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/07 18:10:54 by ronanpoder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

//!-------------------------------CONSTRUCTOR-----------------------------------

Character::Character():
	_name("Anonymous")
{
	for (int i = 0; i < 4; i++)
		this->_items[i] = NULL;
}

Character::Character(std::string name):
	_name(name)
{
	for (int i = 0; i < 4; i++)
		this->_items[i] = NULL;
}

Character::Character(const Character &copy):
	ICharacter(copy)
{
	*this = copy;
}

//!-------------------------------DESTRUCTOR------------------------------------

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_items[i] != NULL)
		{
			delete this->_items[i];
		}
	}
}

//!-------------------------------OPERATOR--------------------------------------

Character	&Character::operator=(const Character &copy)
{
	if (this == &copy)
		return (*this);
	this->_name = copy._name;
	for (int i = 0; i < 4; i++)
	{
		if (this->_items[i] != NULL)
		{
			delete this->_items[i];
			this->_items[i] = NULL;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (copy._items[i] != NULL)
			this->_items[i] = copy._items[i]->clone();
	}

	return(*this);
}

//!-------------------------------ACCESSORS-------------------------------------

const std::string	&Character::getName(void) const
{
	return (this->_name);
}

//!-------------------------------FUNCTIONS-------------------------------------

void	Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i ++)
	{
		if (this->_items[i] == NULL)
		{
			this->_items[i] = m;
			break ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
	{
		this->_items[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter &target)
{
	if (this->_items[idx] != NULL && idx >= 0 && idx < 4)
	{
		this->_items[idx]->use(target);
	}
}
