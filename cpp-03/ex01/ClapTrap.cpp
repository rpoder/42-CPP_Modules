/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:36:42 by ronanpoder        #+#    #+#             */
/*   Updated: 2023/03/02 13:45:24 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :
	_name("Anonymous"),
	_hit_point(10),
	_energy_point(10),
	_attack_damage(0)
{
	std::cout << this->_name << " joined the fight." << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) :
	_name(name),
	_hit_point(10),
	_energy_point(10),
	_attack_damage(0)
{
	std::cout << this->_name << " joined the fight." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &rhs)
{
	*this = rhs;
}

ClapTrap::~ClapTrap()
{
	std::cout << this->_name << " quitted the fight." << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &rhs)
{
	this->_name = rhs.getName();
	this->_hit_point = rhs.getHitPoint();
	this->_energy_point = rhs.getEnergyPoint();
	this->_attack_damage = rhs.getAttackDamage();
	return *this;
}

// ACCESSORS -------------------------------------------------------------------

std::string	ClapTrap::getName() const
{
	return (this->_name);
}

int	ClapTrap::getHitPoint() const
{
	return (this->_hit_point);
}

int	ClapTrap::getEnergyPoint() const
{
	return (this->_energy_point);
}

int	ClapTrap::getAttackDamage() const
{
	return (this->_attack_damage);
}

void	ClapTrap::setName(std::string name)
{
	this->_name = name;
};

void	ClapTrap::setHitPoint(int hit_point)
{
	this->_hit_point = hit_point;
};

void	ClapTrap::setEnergyPoint(int energy_point)
{
	this->_energy_point = energy_point;
};

void	ClapTrap::setAttackDamage(int attack_damage)
{
	this->_attack_damage = attack_damage;
};

// METHODS ---------------------------------------------------------------------

void	ClapTrap::attack(const std::string &target)
{
	if (this->isAlive() == true && this->hasEnergyPoint() == true)
	{
		this->_energy_point--;
		std::cout << this->_name << " attacks " << target
		<< " causing " << this->_attack_damage << " points of damage."
		<< std::endl;
	}
	else
	{
		std::cout << this->_name << " cannot attack." << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->isAlive() == true)
	{
		if (amount < (unsigned int)this->_hit_point)
			this->_hit_point -= amount;
		else
			this->_hit_point = 0;
		std::cout << this->_name << " take damage of "<< amount <<"." << std::endl;
	}
	else
	{
		std::cout << this->_name << "It cannot take damage." << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->isAlive() == true && this->hasEnergyPoint())
	{
		this->_hit_point += amount;
		this->_energy_point--;
	}
	else
	{
		std::cout << this->_name << "It cannot be repaired." << std::endl;
	}
}

bool	ClapTrap::isAlive() const
{
	if (this->_hit_point)
		return (true);
	else
	{
		std::cout << this->_name << " is dead. ";
		return (false);
	}
}

bool	ClapTrap::hasEnergyPoint() const
{
	if (this->_energy_point)
		return (true);
	else
	{
		std::cout << this->_name << " has no more energy point. ";
		return (false);
	}
}
