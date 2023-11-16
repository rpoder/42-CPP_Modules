/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:04:33 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/13 16:32:26 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	b1("Ginette", 150);
	Bureaucrat	b2;

	std::cout << b2 << std::endl;
	b2 = b1;
	std::cout << b2 << std::endl;

	try {
		b2.upgrade();
	}
	catch (Bureaucrat::GradeTooHighException &error)
	{
		std::cout << error.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &error)
	{
		std::cout << error.what() << std::endl;
	}

	std::cout << b2 << std::endl;


	return (0);
}
