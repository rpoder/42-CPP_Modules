/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:43:12 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/13 13:37:53 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

//!-------------------------------CONSTRUCTOR-----------------------------------

RobotomyRequestForm::RobotomyRequestForm():
	AForm("RobotomyForm", 72, 45),
	_target("undefined")
{

}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target):
	AForm("RobotomyForm", 72, 45),
	_target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy):
	AForm("ShrubberyForm", 145, 137)
{
	*this = copy;
}

//!-------------------------------DESTRUCTOR------------------------------------

RobotomyRequestForm::~RobotomyRequestForm()
{

}

//!-------------------------------OPERATOR--------------------------------------

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	AForm::operator=(copy);
	this->_target = copy.getTarget();
	return(*this);
}

//!-------------------------------ACCCESSORS------------------------------------

const std::string &RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

//!-------------------------------FUNCTIONS-------------------------------------

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	int r;

	this->signedGuard(IS_NOT_SIGNED);
	this->gradeGuard(executor.getGrade(), TO_EXECUTE);
	srand (time(NULL));
	r = rand() % 2;
	if (r % 2 == 0)
	{
		std::cout << _target << " has been robotomized successfully" << std::endl;
	}
	else
	{
		std::cout << "Robotomy failed." << std::endl;
	}
}

