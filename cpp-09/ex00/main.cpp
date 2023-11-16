/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:28:40 by rpoder            #+#    #+#             */
/*   Updated: 2023/04/06 18:17:57 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"
#include "Exceptions.hpp"
#include "utils.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "ERR:	Bad arguments, please insert 2 args." << std::endl;
		return (1);
	}
	try
	{
		BitcoinExchange	btc("data.csv");
		btc.displayResults(argv[1]);
	}
	catch (std::exception &error)
	{
		std::cerr << "ERR:	" << error.what() << std::endl;
	}
	return (0);
}
