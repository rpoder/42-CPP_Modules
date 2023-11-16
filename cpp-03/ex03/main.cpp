/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:38:36 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/03 16:27:16 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

void	prinStatus(ClapTrap &c)
{
	std::cout << "----------------------------------" << std::endl;
	std::cout << c.getName() << " has :" << std::endl
	<< c.getHitPoint() << " hit points." << std::endl
	<< c.getEnergyPoint() << " energy points." << std::endl
	<< c.getAttackDamage() << " attack damage." << std::endl;
	std::cout << "----------------------------------" << std::endl << std::endl;
}

void	prinStatus(ScavTrap &c)
{
	std::cout << "----------------------------------" << std::endl;
	std::cout << c.getName() << " has :" << std::endl
	<< c.getHitPoint() << " hit points." << std::endl
	<< c.getEnergyPoint() << " energy points." << std::endl
	<< c.getAttackDamage() << " attack damage." << std::endl;
	std::cout << "----------------------------------" << std::endl << std::endl;
}

void	prinStatus(FragTrap &c)
{
	std::cout << "----------------------------------" << std::endl;
	std::cout << c.getName() << " has :" << std::endl
	<< c.getHitPoint() << " hit points." << std::endl
	<< c.getEnergyPoint() << " energy points." << std::endl
	<< c.getAttackDamage() << " attack damage." << std::endl;
	std::cout << "----------------------------------" << std::endl << std::endl;
}

void	prinStatus(DiamondTrap &c)
{
	std::cout << "----------------------------------" << std::endl;
	std::cout << c.getName() << " has :" << std::endl
	<< c.getHitPoint() << " hit points." << std::endl
	<< c.getEnergyPoint() << " energy points." << std::endl
	<< c.getAttackDamage() << " attack damage." << std::endl;
	std::cout << "----------------------------------" << std::endl << std::endl;
}


int	main(void)
{
	DiamondTrap s1("Jean-Michel");

	prinStatus(s1);

	// for(int i = 0; i <= 100; i++)
	// 	s1.attack("Lulu");

	s1.highFivesGuys();

	s1.takeDamage(100);

	s1.attack("jose");

	// s1.highFivesGuys();
	s1.whoAmI();


	return (0);
}
