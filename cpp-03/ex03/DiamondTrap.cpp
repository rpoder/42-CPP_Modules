/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:21:54 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/02 13:51:09 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

//!-------------------------------CONSTRUCTOR-----------------------------------

DiamondTrap::DiamondTrap():
	ClapTrap("Anonymous_clap_name"),
	ScavTrap("Anonymous_clap_name"),
	FragTrap("Anonymous_clap_name"),
	_name("Anonymous")
{
	std::cout << "DiamondTrap constructor called." << std::endl;
	this->setHitPoint(100);
	this->setEnergyPoint(50);
	this->setAttackDamage(30);
}

DiamondTrap::DiamondTrap(const std::string &name):
	ClapTrap(name + "_clap_name"),
	ScavTrap(name + "_clap_name"),
	FragTrap(name + "_clap_name"),
	_name(name)
{
	std::cout << "DiamondTrap constructor called." << std::endl;
	this->setHitPoint(100);
	this->setEnergyPoint(50);
	this->setAttackDamage(30);
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy):
	ScavTrap(copy),
	FragTrap(copy)
{
	*this = copy;
}

//!-------------------------------DESTRUCTOR------------------------------------

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called." << std::endl;
}

//!-------------------------------OPERATOR--------------------------------------

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &copy)
{
	this->_name = copy._name;
	return(*this);
}

//!-------------------------------METHODS---------------------------------------

void	DiamondTrap::attack(const std::string &target)
{
	std::cout << "DiamondTrap:: ";
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "My name is: " << this->_name << " " << ClapTrap::getName() << std::endl;
}
