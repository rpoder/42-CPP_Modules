/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:03:49 by ronanpoder        #+#    #+#             */
/*   Updated: 2023/02/20 16:15:30 by rpoder           ###   ########.fr       */
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
