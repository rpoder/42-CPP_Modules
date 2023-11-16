/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:38:36 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/01 19:45:40 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void	prinStatus(ClapTrap &c)
{
	std::cout << "----------------------------------" << std::endl;
	std::cout << c.getName() << " has :" << std::endl
	<< c.getHitPoint() << " hit points." << std::endl
	<< c.getEnergyPoint() << " energy points." << std::endl
	<< c.getAttackDamage() << " attack damage." << std::endl;
	std::cout << "----------------------------------" << std::endl;
}

int	main(void)
{
	{
		ClapTrap c1("Jojo");

		prinStatus(c1);

		c1.attack("Lulu");
		c1.attack("Lulu");

		prinStatus(c1);

		c1.takeDamage(8);

		prinStatus(c1);

		c1.attack("Lulu");
		c1.attack("Lulu");
		c1.attack("Lulu");
		c1.attack("Lulu");
		c1.attack("Lulu");
		c1.attack("Lulu");
		c1.attack("Lulu");
		c1.attack("Lulu");
		c1.attack("Lulu");

		prinStatus(c1);
	}
	{
		ClapTrap c2("Tutu");

		prinStatus(c2);

		c2.attack("Lulu");
		c2.attack("Lulu");

		prinStatus(c2);

		c2.takeDamage(12);

		c2.attack("Lulu");

		prinStatus(c2);
	}
	return (0);
}
