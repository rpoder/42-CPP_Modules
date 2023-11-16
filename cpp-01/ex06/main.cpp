/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:09:03 by rpoder            #+#    #+#             */
/*   Updated: 2023/02/16 13:38:24 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HarlFilter.hpp"

int	main(int argc, char **argv)
{
	Harl	h1;

	if (argc != 2)
	{
		std::cout << "ERR:	1 argument is required." << std::endl;
		return (1);
	}

	h1.complain(argv[1]);

	return (0);
}
