/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:03:07 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/06 14:37:13 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
	public:
		Animal();
		Animal(const std::string &type);
		Animal(const Animal &copy);
		virtual ~Animal();

		virtual Animal	&operator=(const Animal &copy);

		std::string	getType() const;

		virtual void	makeSound(void) const;

	protected:
		std::string	_type;
};

#endif
