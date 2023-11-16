/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:17:51 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/08 20:02:45 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

//!-------------------------------CONSTRUCTOR-----------------------------------

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->_saved_materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	*this = copy;
}

//!-------------------------------DESTRUCTOR------------------------------------

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_saved_materia[i] != NULL)
		{
			delete this->_saved_materia[i];
		}
	}
}

//!-------------------------------OPERATOR--------------------------------------

MateriaSource	&MateriaSource::operator=(const MateriaSource &copy)
{
	for (int i = 0; i < 4; i++)
		this->_saved_materia[i] = copy._saved_materia[i];
	return(*this);
}

//!-------------------------------ACCESSORS-------------------------------------

//!-------------------------------FUNCTIONS-------------------------------------

void	MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_saved_materia[i] == NULL)
		{
			this->_saved_materia[i] = m;
			break ;
		}
	}
}

AMateria	*MateriaSource::createMateria(const std::string &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_saved_materia[i] != NULL
			&& type == this->_saved_materia[i]->getType())
		{
			return (this->_saved_materia[i]->clone());
		}
	}
	return (NULL);
}



