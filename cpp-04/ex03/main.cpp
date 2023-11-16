/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:22:58 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/08 20:06:42 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int	main(void)
{
	{
		Character	a;
		Character	b("Jean-Michou");

		AMateria	*i = new Ice();
		AMateria	*j = new Ice();
		AMateria	*o = new Ice();

		a.equip(i);
		b.equip(j);
		b.equip(o);

		a = b;

		a.use(1, b);

		b.unequip(0);
		b.use(0, a);
		b.use(1, a);
		delete j;
	}

	{
		IMateriaSource* src = new MateriaSource();

		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");
		AMateria* tmp;

		tmp = src->createMateria("ice");
		me->equip(tmp);

		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete src;
		delete me;
	}


	return (0);
}
