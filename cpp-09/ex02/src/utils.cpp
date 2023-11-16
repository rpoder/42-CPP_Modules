/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 20:53:27 by rpoder            #+#    #+#             */
/*   Updated: 2023/04/11 10:33:03 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

bool	isPositive(int num)
{
	return (num >= 0);
}

bool	isDigit(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
			return (false);
	}
	return (true);
}

bool	isOverflowing(std::string str)
{
	double	num;

	num = std::atof(str.c_str());
	if (num > INT_MAX || num < INT_MIN)
		return (false);
	return (true);
}

void	printPairs(std::vector<std::pair<int, int> > container)
{
	std::cout << "---------------" << std::endl;
	for (std::vector<std::pair<int, int> >::const_iterator it = container.begin(); it != container.end(); it++)
	{
		std::cout << "(" << it->first << ", " << it->second << ")" << std::endl;
	}
}


