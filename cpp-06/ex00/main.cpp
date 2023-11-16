/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:09:39 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/26 15:15:55 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "ERR:	No parameter. Please insert a char, int, float or double." << std::endl;
		return (1);
	}

	try {
		ScalarConverter::convert(argv[1]);
	}
	catch(std::exception &error)
	{
		std::cerr << error.what() << std::endl;
	}
	return (0);
}
