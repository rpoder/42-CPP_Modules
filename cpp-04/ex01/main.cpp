/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:12:37 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/08 20:39:52 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int	main(void)
{
	Cat		*cat1 = new Cat();

	Brain	*brain1 = new Brain();

	for (int i = 0; i < 50; i++)
	{
		brain1->setIdea(i, "Where is my bone ?");
	}
	for (int i = 49; i < 100; i++)
	{
		brain1->setIdea(i, "Gonna eat that bird !");
	}

	cat1->setBrain(brain1);

	brain1->setIdea(0, "Toz");

	Cat		*cat2 = new Cat(*cat1);


	Brain *brain2 = cat2->getBrain();

	for (int i = 0; i < 100; i++)
	{
		std::cout << i << "	" << brain2->getIdea(i) << std::endl;
	}

	delete cat1;
	delete cat2;

	{
		Animal	*zoo[10];

		for (int i = 0; i < 5; i++)
			zoo[i] = new Cat();

		for (int i = 5; i < 10; i++)
			zoo[i] = new Dog();

		for (int i = 0; i < 10; i++)
			zoo[i]->makeSound();

		for (int i = 0; i < 10; i++)
			delete zoo[i];
	}

	Dog basic;
	{
		Dog tmp = basic;
	}

	return (0);
}
