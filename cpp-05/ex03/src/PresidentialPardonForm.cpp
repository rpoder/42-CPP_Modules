/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:43:12 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/13 13:37:53 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

//!-------------------------------CONSTRUCTOR-----------------------------------

PresidentialPardonForm::PresidentialPardonForm():
	AForm("PresidentialPardonForm", 25, 5),
	_target("undefined")
{

}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target):
	AForm("PresidentialPardonForm", 25, 5),
	_target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy):
	AForm("ShrubberyForm", 145, 137)
{
	*this = copy;
}

//!-------------------------------DESTRUCTOR------------------------------------

PresidentialPardonForm::~PresidentialPardonForm()
{

}

//!-------------------------------OPERATOR--------------------------------------

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	AForm::operator=(copy);
	this->_target = copy.getTarget();
	return(*this);
}

//!-------------------------------ACCCESSORS------------------------------------

const std::string &PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

//!-------------------------------FUNCTIONS-------------------------------------

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	this->signedGuard(IS_NOT_SIGNED);
	this->gradeGuard(executor.getGrade(), TO_EXECUTE);
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
