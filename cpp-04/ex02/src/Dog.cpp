/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:19:02 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/08 20:46:08 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

//!-------------------------------CONSTRUCTOR-----------------------------------

Dog::Dog():
	AAnimal("Dog"),
	_brain(new Brain)

{
	std::cout << "Dog constructor called." << std::endl;
}

Dog::Dog(const Dog &copy):
	AAnimal(),
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
	std::cout << "Cat operator = called." << std::endl;
	if (this != &copy)
	{
		this->_type = copy._type;
		//
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
