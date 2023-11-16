/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:19:02 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/06 12:40:55 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//!-------------------------------CONSTRUCTOR-----------------------------------

Cat::Cat():
	Animal("Cat")
{
	std::cout << "Cat constructor called." << std::endl;
}

Cat::Cat(const Cat &copy)
{
	std::cout << "Cat copy constructor called." << std::endl;
	*this = copy;
}

//!-------------------------------DESTRUCTOR------------------------------------

Cat::~Cat()
{
	std::cout << "Cat destructor called." << std::endl;
}

//!-------------------------------OPERATOR--------------------------------------

Cat	&Cat::operator=(const Cat &copy)
{
	this->_type = copy._type;
	return(*this);
}

//!-------------------------------ACCESSORS-------------------------------------

//!-------------------------------FUNCTIONS-------------------------------------

void	Cat::makeSound(void) const
{
	std::cout << "Miaou Miou !!!" << std::endl;
}
