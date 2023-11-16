/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:20:07 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/06 16:53:15 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat:
	virtual public Animal
{
	public:
		Cat();
		Cat(const Cat &copy);
		~Cat();

		Cat	&operator=(const Cat &copy);

		void	makeSound(void) const;

		void	setBrain(Brain *ptr);
		Brain	*getBrain();

	private:
		Brain	*_brain;
};

#endif
