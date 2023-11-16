/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:03:49 by ronanpoder        #+#    #+#             */
/*   Updated: 2023/02/20 16:26:48 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	this->name = "Anonymous";
	std::cout << this->name;
	std::cout << " is born." << std::endl;
}

Zombie::Zombie(std::string name) : name(name)
{
	std::cout << this->name;
	std::cout << " is born." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->name;
	std::cout << " is dead." << std::endl;
}

void	Zombie::announce(void) const
{
	std::cout << this->name;
	std::cout << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	if (name.length() == 0)
	{
		std::cout << "You cannot initialize a name with nothing." << std::endl;
		return;
	}
	std::cout << this->name;
	std::cout << "'s name set to \"" << name  << "\"."<< std::endl;
	this->name = name;
	return ;
}
