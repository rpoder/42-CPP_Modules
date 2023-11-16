/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:56:56 by ronanpoder        #+#    #+#             */
/*   Updated: 2023/02/20 16:16:51 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int n, std::string name){
	Zombie	*zombieHorde;
	int		i;

	if (n <= 0)
		return (NULL);
	zombieHorde = new Zombie[n];
	i = 0;
	while (i < n)
	{
		zombieHorde[i].setName(name);
		i++;
	}

	return (zombieHorde);
}
