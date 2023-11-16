/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:04:33 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/14 16:41:10 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Bureaucrat	jojo = Bureaucrat("Jojo", 1);
	Intern		stagiaire;
	AForm		*form;

	form = stagiaire.makeForm("PresidentialPardon", "hello");

	if (form != NULL)
	{
		jojo.signForm(*form);
		jojo.executeForm(*form);
		delete form;
	}
	return (0);
}
