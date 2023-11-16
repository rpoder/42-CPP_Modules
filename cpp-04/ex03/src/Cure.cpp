/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:48:23 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/08 18:59:38 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

//!-------------------------------CONSTRUCTOR-----------------------------------

Cure::Cure():
	AMateria("cure")
{

}

Cure::Cure(const Cure &copy):
	AMateria(copy)
{
	*this = copy;
}

//!-------------------------------DESTRUCTOR------------------------------------

Cure::~Cure()
{

}

//!-------------------------------OPERATOR--------------------------------------

Cure	&Cure::operator=(const Cure &copy)
{
	(void) copy;
	return(*this);
}

//!-------------------------------ACCESSORS-------------------------------------

//!-------------------------------FUNCTIONS-------------------------------------

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wound *";
}

AMateria	*Cure::clone() const
{
	return (new Cure());
}
