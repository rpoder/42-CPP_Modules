/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:12:37 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/08 20:32:08 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	{
		Animal	*meta = new Animal();
		Animal	*i = new Dog();
		Animal	*j = new Cat();
		Dog		*k = new Dog();
		Dog		*l = new Dog(*k);

		std::cout << i->getType() << " " << std::endl;
		std::cout << j->getType() << " " << std::endl;
		std::cout << k->getType() << " " << std::endl;
		std::cout << l->getType() << " " << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();

		delete i;
		delete j;
		delete k;
		delete l;
		delete meta;
	}
	{
		WrongAnimal	*m = new WrongAnimal();
		WrongAnimal	*n = new WrongCat();

		std::cout << m->getType() << " " << std::endl;
		std::cout << n->getType() << " " << std::endl;

		m->makeSound();
		n->makeSound();

		delete m;
		delete n;
	}

	return (0);
}
