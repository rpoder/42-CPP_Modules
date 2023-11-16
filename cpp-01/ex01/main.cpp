/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:53:14 by ronanpoder        #+#    #+#             */
/*   Updated: 2023/02/20 16:33:55 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*horde;

	horde = zombieHorde(3, "Zombie de la horde");
	for (int i = 0; i < 3; i++)
	{
		horde[i].announce();
	}
	delete[] horde;
	return (0);
}
