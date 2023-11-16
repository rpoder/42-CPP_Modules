/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:21:54 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/03 16:17:33 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

//!-------------------------------CONSTRUCTOR-----------------------------------

FragTrap::FragTrap(): ClapTrap()
{
	std::cout << "FragTrap constructor called." << std::endl;
	this->setHitPoint(100);
	this->setEnergyPoint(50);
	this->setAttackDamage(20);
}

FragTrap::FragTrap(const std::string &name): ClapTrap(name)
{
	std::cout << "FragTrap constructor called." << std::endl;
	this->setHitPoint(100);
	this->setEnergyPoint(100);
	this->setAttackDamage(30);
}

FragTrap::FragTrap(const FragTrap &copy): ClapTrap(copy)
{
	*this = copy;
}

//!-------------------------------DESTRUCTOR------------------------------------

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called." << std::endl;
}

//!-------------------------------OPERATOR--------------------------------------

FragTrap	&FragTrap::operator=(const FragTrap &copy)
{
	this->_name = copy._name;
	return(*this);
}

//!-------------------------------METHODS---------------------------------------

void	FragTrap::attack(const std::string &target)
{
	std::cout << "FragTrap:: ";
	ClapTrap::attack(target);
}

void	FragTrap::highFivesGuys(void)
{
	if (this->isAlive() == true)
	{
		std::cout << "High five or not ?";
	}
	else
	{
		std::cout << "He sadly cannot highfive you.";
	}
	std::cout << std::endl;
}
