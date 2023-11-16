/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 17:22:51 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/27 11:39:12 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "iostream"

Base	*generate(void)
{
	int	randomized;

	srand (time(NULL));
	randomized = rand() % 3;
	if (randomized == 0)
		return (new A);
	if (randomized == 1)
		return (new B);
	if (randomized == 2)
		return (new C);
	return (NULL);
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Type undefined" << std::endl;
}

void	identify(Base &p)
{
	int	res;

	res = 0;
	try {
		(void) dynamic_cast<A&>(p);
	}
	catch(std::exception &error)
	{
		res += 1;
	}
	try {
		(void) dynamic_cast<B&>(p);
	}
	catch(std::exception &error)
	{
		res += 2;
	}
	try {
		(void) dynamic_cast<C&>(p);
	}
	catch(std::exception &error)
	{
		res += 3;
	}
	switch (res)
	{
		case(5):
			std::cout << "A" << std::endl;
			break ;
		case(4):
			std::cout << "B" << std::endl;
			break ;
		case(3):
			std::cout << "C" << std::endl;
			break ;
		default:
			std::cout << "Type undefined" << std:: endl;
	}
}

int	main(void)
{
	Base *test;
	test = generate();

	Base &test_bis = *test;
	identify(test);
	identify(test_bis);
	return (0);
}
