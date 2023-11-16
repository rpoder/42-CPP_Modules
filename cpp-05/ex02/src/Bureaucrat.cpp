/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:05:09 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/13 14:53:15 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//!-------------------------------CONSTRUCTOR-----------------------------------

Bureaucrat::Bureaucrat():
	_name("Anonymous"),
	_grade(150)
{}

Bureaucrat::Bureaucrat(const std::string &name, size_t grade):
	_name(name)
{
	this->gradeGuard(grade);
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	*this = copy;
}

//!-------------------------------DESTRUCTOR------------------------------------

Bureaucrat::~Bureaucrat()
{

}

//!-------------------------------OPERATOR--------------------------------------

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &copy)
{
	std::string	*tmp;

	tmp = const_cast<std::string *>(&this->_name);
	*tmp = copy.getName();
	this->_grade = copy.getGrade();
	return(*this);
}

std::ostream	&operator<<(std::ostream& os, Bureaucrat b)
{
	std::cout << b.getName() << ", bureaucrat grade is " << b.getGrade();
	return (os);
}

//!-------------------------------ACCESSORS-------------------------------------

const std::string	&Bureaucrat::getName(void) const
{
	return (this->_name);
}

size_t	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

//!-------------------------------FUNCTIONS-------------------------------------

void	Bureaucrat::gradeGuard(size_t grade) const
{
	if (grade < 1)
	{
		throw(Bureaucrat::GradeTooHighException());
	}
	else if (grade > 150)
	{
		throw(Bureaucrat::GradeTooLowException());
	}
}

//!-------------------------------MEMBER_CLASSES-------------------------------------

void	Bureaucrat::upgrade()
{
	this->gradeGuard(this->_grade - 1);
	this->_grade--;
}

void	Bureaucrat::downgrade()
{
	this->gradeGuard(this->_grade + 1);
	this->_grade++;
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high.");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low.");
}

void	Bureaucrat::signForm(AForm &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << this->_name << " signed " << f.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->_name << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
	}

}

void	Bureaucrat::executeForm(const AForm &f)
{
	try {
		f.execute(*this);
		std::cout << this->_name << " executed " << f.getName() << std::endl;
	}
	catch (AForm::NotSignedException &e)
	{
		std::cerr << _name<< " couldn't execute " << f.getName()
		<< " because " << e.what() << std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cerr << _name<< " couldn't execute " << f.getName()
		<< " because " << _name << "'s " << e.what() << std::endl;
	}
}

