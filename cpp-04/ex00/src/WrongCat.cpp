/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:19:02 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/06 12:40:55 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

//!-------------------------------CONSTRUCTOR-----------------------------------

WrongCat::WrongCat():
	WrongAnimal("WrongCat")
{
	std::cout << "WrongCat constructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy):
	WrongAnimal(copy)
{
	std::cout << "WrongCat copy constructor called." << std::endl;
	*this = copy;
}

//!-------------------------------DESTRUCTOR------------------------------------

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called." << std::endl;
}

//!-------------------------------OPERATOR--------------------------------------

WrongCat	&WrongCat::operator=(const WrongCat &copy)
{
	this->_type = copy._type;
	return(*this);
}

//!-------------------------------ACCESSORS-------------------------------------

//!-------------------------------FUNCTIONS-------------------------------------

void	WrongCat::makeSound(void) const
{
	std::cout << "[bugged] Miaou Miou !!!" << std::endl;
}
