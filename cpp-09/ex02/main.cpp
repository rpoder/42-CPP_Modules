/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:45:21 by rpoder            #+#    #+#             */
/*   Updated: 2023/04/11 10:49:29 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	std::vector<int>	test;
	std::deque<int>		test2;
	PmergeMe			p;
	int					num;

	argv++;
	if (argc <= 1)
	{
		std::cout << "Error:	Please insert at least 1 argument." << std::endl;
		return (1);
	}
	for (int i = 0; i < (argc - 1); i++)
	{
		if (isDigit(argv[i]) && isPositive(atoi(argv[i])) && isOverflowing(argv[i]))
		{
			num = atoi(argv[i]);
			test.push_back(num);
			test2.push_back(num);
		}
		else
		{
			std::cout << "Error:	Please insert only positive integers." << std::endl;
			return (1);
		}
	}
	p.sort(test);
	p.sort(test2);

	return (0);
}
