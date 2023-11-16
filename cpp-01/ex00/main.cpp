/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:53:14 by ronanpoder        #+#    #+#             */
/*   Updated: 2023/02/20 15:45:29 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	no_name_zombie;
	{
		Zombie	stack_zombie("Stack Zombie");
	}
	Zombie	*heap_zombie;
	heap_zombie = newZombie("Heap Zombie");
	randomChump("Random Chump");
	delete heap_zombie;
	return (0);
}
