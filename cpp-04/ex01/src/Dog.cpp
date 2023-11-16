/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:19:02 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/08 20:41:34 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

//!-------------------------------CONSTRUCTOR-----------------------------------

Dog::Dog():
	Animal("Dog"),
	_brain(new Brain)

{
	std::cout << "Dog constructor called." << std::endl;
}

Dog::Dog(const Dog &copy):
	Animal(copy),
	_brain(new Brain)
{
	std::cout << "Dog copy constructor called." << std::endl;
	*this = copy;
}

//!-------------------------------DESTRUCTOR------------------------------------

Dog::~Dog()
{
	delete	this->_brain;
	std::cout << "Dog destructor called." << std::endl;
}

//!-------------------------------OPERATOR--------------------------------------

Dog	&Dog::operator=(const Dog &copy)
{
	std::cout << "Dog operator = called." << std::endl;
	if (this != &copy)
	{
		this->_type = copy._type;
		// dereference to use the = operator of two brains
		*this->_brain = *copy._brain;
	}
	return(*this);
}

//!-------------------------------ACCESSORS-------------------------------------

//!-------------------------------FUNCTIONS-------------------------------------

void	Dog::makeSound(void) const
{
	std::cout << "Woof Woof !!!" << std::endl;
}
