/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:25:52 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/08 20:33:54 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

//!-------------------------------CONSTRUCTOR-----------------------------------

Brain::Brain()
{
	std::cout << "Brain constructor called." << std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain copy constructor called." << std::endl;
	*this = copy;
}

//!-------------------------------DESTRUCTOR------------------------------------

Brain::~Brain()
{
	std::cout << "Brain destructor called." << std::endl;
}

//!-------------------------------OPERATOR--------------------------------------

Brain	&Brain::operator=(const Brain &copy)
{
	std::cout << "Brain operator custructor called." << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = copy._ideas[i];
	return(*this);
}

//!-------------------------------ACCESSORS-------------------------------------

void	Brain::setIdea(size_t index, const std::string str)
{
	if (index >= 100)
		std::cout << "Max size is reached." << std::endl;
	else
	{
		this->_ideas[index] = str;
	}
}

std::string	Brain::getIdea(size_t index)
{
	if (index >= 100)
	{
		std::cout << index <<" is not in the tab." << std::endl;
		return ("undefined");
	}
	return(this->_ideas[index]);
}

//!-------------------------------FUNCTIONS-------------------------------------
