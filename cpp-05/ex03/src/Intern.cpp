/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ronanpoder <ronanpoder@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:05:22 by ronanpoder        #+#    #+#             */
/*   Updated: 2023/03/14 12:46:56 by ronanpoder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

//!-------------------------------CONSTRUCTOR-----------------------------------

Intern::Intern()
{

}

Intern::Intern(const Intern &copy)
{
	*this = copy;
}

//!-------------------------------DESTRUCTOR------------------------------------

Intern::~Intern()
{

}

//!-------------------------------OPERATOR--------------------------------------

Intern	&Intern::operator=(const Intern &copy)
{
	(void) copy;
	return(*this);
}

//!-------------------------------ACCESSORS-------------------------------------

//!-------------------------------FUNCTIONS-------------------------------------

AForm	*Intern::makeShrubberyCreationForm(std::string target) const
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::makeRobotomyRequestForm(std::string target) const
{
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::makePresidentialPardonForm(std::string target) const
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string form, std::string target)
{
	std::string	available[3] = {"ShrubberyCreation", "RobotomyRequest", "PresidentialPardon"};

	AForm *(Intern::*forms[3])(std::string target) const =
	{
		&Intern::makeShrubberyCreationForm,
		&Intern::makeRobotomyRequestForm,
		&Intern::makePresidentialPardonForm
	};

	for (int i = 0; i < 3; i++)
	{
		if (available[i].compare(form) == 0)
		{
			std::cout << "Intern creates " << available[i] << std::endl;
			return ((*this).*(forms[i]))(target);
		}
	}
	std::cerr << "The form for doesn't exist" << std::endl;
	return (NULL);
}
