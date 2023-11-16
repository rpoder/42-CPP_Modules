/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:21:54 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/03 16:30:35 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

//!-------------------------------CONSTRUCTOR-----------------------------------

ScavTrap::ScavTrap(): ClapTrap()
{
	std::cout << "ScavTrap constructor called." << std::endl;
	this->setHitPoint(100);
	this->setEnergyPoint(50);
	this->setAttackDamage(20);
}

ScavTrap::ScavTrap(const std::string &name): ClapTrap(name)
{
	std::cout << "ScavTrap constructor called." << std::endl;
	this->setHitPoint(100);
	this->setEnergyPoint(50);
	this->setAttackDamage(20);
}

ScavTrap::ScavTrap(const ScavTrap &copy): ClapTrap(copy)
{
	*this = copy;
}

//!-------------------------------DESTRUCTOR------------------------------------

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called." << std::endl;
}

//!-------------------------------OPERATOR--------------------------------------

ScavTrap	&ScavTrap::operator=(const ScavTrap &copy)
{
	this->_name = copy._name;
	return(*this);
}

//!-------------------------------METHODS---------------------------------------

void	ScavTrap::guardGate()
{
	if (this->isAlive() == true)
	{
		std::cout << "Gate Keeper mode activated.";
	}
	std::cout << std::endl;
}
