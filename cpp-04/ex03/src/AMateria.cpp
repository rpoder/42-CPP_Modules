/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:30:43 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/08 19:28:51 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

//!-------------------------------CONSTRUCTOR-----------------------------------

AMateria::AMateria()
{

}

AMateria::AMateria(const std::string &type):
	_type(type)
{

}

AMateria::AMateria(const AMateria &copy)
{
	*this = copy;
}

//!-------------------------------DESTRUCTOR------------------------------------

AMateria::~AMateria()
{

}

//!-------------------------------OPERATOR--------------------------------------

AMateria	&AMateria::operator=(const AMateria &copy)
{
	this->_type = copy._type;

	return(*this);
}

//!-------------------------------ACCESSORS-------------------------------------

std::string	AMateria::getType() const
{
	return (this->_type);
}

//!-------------------------------FUNCTIONS-------------------------------------

void	AMateria::use(ICharacter &target)
{
	(void) target;
	std::cout << "[AMatera::use function called]" << std::endl;
}
