/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:57:58 by ronanpoder        #+#    #+#             */
/*   Updated: 2022/12/06 18:15:37 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <stdlib.h>

class Zombie
{
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();

		void	announce(void) const;
		void	setName(std::string name);

	private:
		std::string	name;
};

void	randomChump( std::string name );
Zombie	*newZombie( std::string name );
Zombie	*zombieHorde(int n, std::string name);

#endif
