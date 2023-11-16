/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:28:40 by rpoder            #+#    #+#             */
/*   Updated: 2023/04/04 15:46:33 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	RPN	test;

	if (argc != 2)
	{
		std::cerr << "ERR:	One argument is required." << std::endl;
		return (1);
	}
	try
	{
		std::cout << test.compute(argv[1]) << std::endl;
	}
	catch (std::invalid_argument &error)
	{
		std::cerr << "Error" << std::endl;
		// std::cerr << "ERR:	invalid_argument "<< error.what() << std::endl;
	}

	return (0);
}
