/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:09:50 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/06 12:40:49 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

//!-------------------------------CONSTRUCTOR-----------------------------------

WrongAnimal::WrongAnimal():
	_type("Undefined")
{
	std::cout << "WrongAnimal constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type):
	_type(type)
{
	std::cout << "WrongAnimal constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "WrongAnimal copy constructor called." << std::endl;
	*this = copy;
}

//!-------------------------------DESTRUCTOR------------------------------------

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called." << std::endl;
}

//!-------------------------------OPERATOR--------------------------------------

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &copy)
{
	this->_type = copy._type;
	return(*this);
}

//!-------------------------------ACCESSORS-------------------------------------

std::string	WrongAnimal::getType() const
{
	return (this->_type);
}

//!-------------------------------FUNCTIONS-------------------------------------

void	WrongAnimal::makeSound(void) const
{
	std::cout << "[bugged] " << this->_type << " is making a sound." << std::endl;
}
