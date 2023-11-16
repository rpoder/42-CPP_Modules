/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 20:48:13 by rpoder            #+#    #+#             */
/*   Updated: 2023/04/11 10:32:28 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <ctime>
# include <iomanip>
# include <cstdlib>
# include <iostream>
# include <vector>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <climits>
# include <bits/stdc++.h>
# include <ctime>

bool	isPositive(int num);
bool	isDigit(std::string str);
bool	isOverflowing(std::string str);

template <typename T>
void	printContainer(T container, std::string moment)
{
	size_t	i;

	i = 0;
	std::cout << moment;
	for (typename T::iterator it = container.begin(); it != container.end(); it++, i++)
	{
		if (i < 5)
		{
			std::cout << *it << " ";
		}
		else
		{
			std::cout << "[...]";
			break ;
		}
	}
	std::cout << std::endl;
}

template <typename T>
int	binarySearch(int num, T container)
{
	int	median;
	int	left;
	int	right;

	left = 0;
	right = container.size() - 1;
	while (left <= right)
	{
		median = floor((left + right) / 2);
		if (container[median] < num)
			left = median + 1;
		else if (container[median] > num)
			right = median - 1;
		else
			return (median);
	}
	return (left);
}

template <typename T>
void	printTime(T container, struct timespec begin, std::string container_type)
{
	struct timespec	end;
	double			time_taken;

	clock_gettime(CLOCK_MONOTONIC, &end);

	time_taken = (end.tv_sec - begin.tv_sec) * 1e3;
	time_taken = (time_taken + (end.tv_nsec - begin.tv_nsec)) * 1e-3;


	std::cout << std::fixed;
	if (container.size() == 1)
	{
		std::cout << "Time to process a range of " << container.size() <<
		" element with std::" << container_type << " :	" << std::setprecision(5) << time_taken << " us" << std::endl;
	}
	else
	{
		std::cout << "Time to process a range of " << container.size() <<
		" elements with std::" << container_type << " :	" << std::setprecision(5) << time_taken << " us" << std::endl;
	}

}

void	printPairs(std::vector<std::pair<int, int> > container);

#endif
