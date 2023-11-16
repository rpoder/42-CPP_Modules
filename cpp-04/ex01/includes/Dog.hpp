/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:20:07 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/06 16:53:10 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog:
	virtual public Animal
{
	public:
		Dog();
		Dog(const Dog &copy);
		~Dog();

		Dog	&operator=(const Dog &copy);

		void	makeSound(void) const;

		void	setBrain(Brain *ptr);
		Brain	*getBrain();

	private:
		Brain	*_brain;

};

#endif
