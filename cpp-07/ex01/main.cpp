/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:28:40 by rpoder            #+#    #+#             */
/*   Updated: 2023/04/05 12:00:38 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	print_one(const int &i)
{
	std::cout << i << std::endl;
}

int	main()
{
	int	tab[3];

	for (int i = 0; i < 3; i++)
		tab[i] = i;
	::iter(tab, 3, &print_one);
	return (0);
}
