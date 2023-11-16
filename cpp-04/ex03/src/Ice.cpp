/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:48:23 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/08 20:02:17 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

//!-------------------------------CONSTRUCTOR-----------------------------------

Ice::Ice():
	AMateria("ice")
{

}

Ice::Ice(const Ice &copy):
	AMateria(copy)
{
	*this = copy;
}

//!-------------------------------DESTRUCTOR------------------------------------

Ice::~Ice()
{

}

//!-------------------------------OPERATOR--------------------------------------

Ice	&Ice::operator=(const Ice &copy)
{
	(void) copy;
	return(*this);
}

//!-------------------------------ACCESSORS-------------------------------------

//!-------------------------------FUNCTIONS-------------------------------------

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria	*Ice::clone() const
{
	return (new Ice());
}
