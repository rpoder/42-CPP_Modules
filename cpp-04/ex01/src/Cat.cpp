/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:19:02 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/06 16:57:37 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//!-------------------------------CONSTRUCTOR-----------------------------------

Cat::Cat():
	Animal("Cat"),
	_brain(new Brain)
{
	std::cout << "Cat constructor called." << std::endl;
}

Cat::Cat(const Cat &copy):
	Animal(),
	_brain(new Brain)
{
	std::cout << "Cat copy constructor called." << std::endl;
	*this = copy;
}

//!-------------------------------DESTRUCTOR------------------------------------

Cat::~Cat()
{
	delete	this->_brain;
	std::cout << "Cat destructor called." << std::endl;
}

//!-------------------------------OPERATOR--------------------------------------

Cat	&Cat::operator=(const Cat &copy)
{
	std::cout << "Cat operator = called." << std::endl;
	if (this != &copy)
	{
		this->_type = copy._type;
		// dereference to use the = operator of two brains
		*this->_brain = *copy._brain;
	}

	return(*this);
}

//!-------------------------------ACCESSORS-------------------------------------

void	Cat::setBrain(Brain *ptr)
{
	delete this->_brain;
	this->_brain = ptr;
}

Brain	*Cat::getBrain()
{
	return (this->_brain);
}

//!-------------------------------FUNCTIONS-------------------------------------

void	Cat::makeSound(void) const
{
	std::cout << "Miaou Miou !!!" << std::endl;
}
