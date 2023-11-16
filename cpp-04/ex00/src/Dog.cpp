/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:19:02 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/06 12:40:58 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

//!-------------------------------CONSTRUCTOR-----------------------------------

Dog::Dog():
	Animal("Dog")
{
	std::cout << "Dog constructor called." << std::endl;
}

Dog::Dog(const Dog &copy)
{
	std::cout << "Dog copy constructor called." << std::endl;
	*this = copy;
}

//!-------------------------------DESTRUCTOR------------------------------------

Dog::~Dog()
{
	std::cout << "Dog destructor called." << std::endl;
}

//!-------------------------------OPERATOR--------------------------------------

Dog	&Dog::operator=(const Dog &copy)
{
	this->_type = copy._type;
	return(*this);
}

//!-------------------------------ACCESSORS-------------------------------------

//!-------------------------------FUNCTIONS-------------------------------------

void	Dog::makeSound(void) const
{
	std::cout << "Woof Woof !!!" << std::endl;
}
