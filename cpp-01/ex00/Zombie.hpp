/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ronanpoder <ronanpoder@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:57:58 by ronanpoder        #+#    #+#             */
/*   Updated: 2022/11/15 12:27:07 by ronanpoder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __HEADER_HPP__
#define __HEADER_HPP__

# include <iostream>
# include <ctype.h>

class Zombie
{
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();

		void	announce(void) const;

	private:
		std::string	name;
};

void	randomChump( std::string name );
Zombie	*newZombie( std::string name );
Zombie	*zombieHorde(int n, std::string name);


#endif // __HEADER_HPP__
