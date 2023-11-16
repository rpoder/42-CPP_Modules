/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:28:40 by rpoder            #+#    #+#             */
/*   Updated: 2023/04/06 17:43:43 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Easyfind.hpp"
#include <iostream>
#include <vector>
#include <deque>

int	main()
{
	std::vector<int>	v1;
	std::deque<int>		v2;

	v1.push_back(11);
	v1.push_back(22);
	v1.push_back(33);

	v2.push_back(11);
	v2.push_back(22);
	v2.push_back(33);

	try {
		std::cout << *eastfind(v1, 22) << std::endl;
		std::cout << *eastfind(v2, 22) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "ERR:	not found." << std::endl;
	}
	return (0);
}
