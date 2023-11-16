/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:04:33 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/13 16:58:12 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	Bureaucrat	b1("Ginette", 1);
	ShrubberyCreationForm	f("Tree");
	RobotomyRequestForm		g("Benoit");
	PresidentialPardonForm	h("Macron");

	std::cout << f << std::endl;
	std::cout << g << std::endl;
	std::cout << h << std::endl;
	b1.signForm(h);
	b1.signForm(h);
	b1.executeForm(h);

	return (0);
}
