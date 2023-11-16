/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:09:50 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/06 18:17:05 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

//!-------------------------------CONSTRUCTOR-----------------------------------

AAnimal::AAnimal():
	_type("Undefined")
{
	std::cout << "AAnimal constructor called." << std::endl;
}

AAnimal::AAnimal(const std::string &type):
	_type(type)
{
	std::cout << "AAnimal constructor called." << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy)
{
	std::cout << "AAnimal copy constructor called." << std::endl;
	*this = copy;
}

//!-------------------------------DESTRUCTOR------------------------------------

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called." << std::endl;
}

//!-------------------------------OPERATOR--------------------------------------

AAnimal	&AAnimal::operator=(const AAnimal &copy)
{
	std::cout << "AAnimal operator = called." << std::endl;
	this->_type = copy._type;
	return(*this);
}

//!-------------------------------ACCESSORS-------------------------------------

std::string	AAnimal::getType() const
{
	return (this->_type);
}

