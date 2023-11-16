/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:09:50 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/06 12:40:49 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

//!-------------------------------CONSTRUCTOR-----------------------------------

Animal::Animal():
	_type("Undefined")
{
	std::cout << "Animal constructor called." << std::endl;
}

Animal::Animal(const std::string &type):
	_type(type)
{
	std::cout << "Animal constructor called." << std::endl;
}

Animal::Animal(const Animal &copy)
{
	std::cout << "Animal copy constructor called." << std::endl;
	*this = copy;
}

//!-------------------------------DESTRUCTOR------------------------------------

Animal::~Animal()
{
	std::cout << "Animal destructor called." << std::endl;
}

//!-------------------------------OPERATOR--------------------------------------

Animal	&Animal::operator=(const Animal &copy)
{
	this->_type = copy._type;
	return(*this);
}

//!-------------------------------ACCESSORS-------------------------------------

std::string	Animal::getType() const
{
	return (this->_type);
}

//!-------------------------------FUNCTIONS-------------------------------------

void	Animal::makeSound(void) const
{
	std::cout << this->_type << " is making a sound." << std::endl;
}
