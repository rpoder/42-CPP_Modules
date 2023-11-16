/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:28:40 by rpoder            #+#    #+#             */
/*   Updated: 2023/04/10 09:55:42 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#define MAX_SIZE 10000

int	main()
{
	{
		try
		{
			Span	sp(5);

			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
			::printContainer(sp._tab);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		try
		{
			Span	sp(3);
			Span	sp2(5);

			sp.addNumber(88);
			sp.addNumber(99);
			sp.addNumber(111);
			sp2.addNumber(1);
			sp2.addNumber(2);
			sp2.addNumbers(sp._tab.begin(), sp._tab.end());
			::printContainer(sp2._tab);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		try
		{
			Span	sp2(0);
			Span sp(MAX_SIZE);

			for (int i = 0; i < MAX_SIZE; i++)
				sp.addNumber(i);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
			// ::printContainer(sp._tab);
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return (0);
}
