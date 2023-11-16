/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:53:44 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/10 17:30:04 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

//!-------------------------------CONSTRUCTOR-----------------------------------

AForm::AForm():
	_name("undefined"),
	_is_signed(false),
	_grade_to_sign(150),
	_grade_to_execute(150)
{

}

AForm::AForm(std::string name, size_t grade_to_sign, size_t grade_to_execute):
	_name(name),
	_is_signed(false),
	_grade_to_sign(150),
	_grade_to_execute(150)
{
	size_t	*tmp_to_sign;
	size_t	*tmp_to_execute;

	gradeGuard(grade_to_sign, TO_SUBMIT);
	gradeGuard(grade_to_execute, TO_SUBMIT);
	tmp_to_sign = const_cast<size_t *>(&this->_grade_to_sign);
	tmp_to_execute = const_cast<size_t *>(&this->_grade_to_execute);
	*tmp_to_sign  = grade_to_sign;
	*tmp_to_execute = grade_to_execute;
}

AForm::AForm(const AForm &copy):
	_grade_to_sign(150),
	_grade_to_execute(150)
{
	*this = copy;
}

//!-------------------------------DESTRUCTOR------------------------------------

AForm::~AForm()
{

}

//!-------------------------------OPERATOR--------------------------------------

AForm	&AForm::operator=(const AForm &copy)
{
	std::string	*tmp;
	size_t		*tmp_to_sign;
	size_t		*tmp_to_execute;

	tmp = const_cast<std::string *>(&this->_name);
	*tmp = copy.getName();
	this->_is_signed = copy.getIsSigned();

	tmp_to_sign = const_cast<size_t *>(&this->_grade_to_sign);
	tmp_to_execute = const_cast<size_t *>(&this->_grade_to_execute);
	*tmp_to_sign  = copy.getGradeToSign();
	*tmp_to_execute = copy.getGradeToExecute();
	return(*this);
}

std::ostream	&operator<<(std::ostream& os, AForm &f)
{
	std::cout << "------------FORM " << f.getName() << std::endl;
	std::cout << "is_signed: " << f.getIsSigned() << std::endl;
	std::cout << "minimum grade to sign: " << f.getGradeToSign() << std::endl;
	std::cout << "minimum grade to execute: " << f.getGradeToExecute() << std::endl;
	return (os);
}

//!-------------------------------ACCESSORS-------------------------------------

std::string	AForm::getName() const
{
	return (this->_name);
}

bool	AForm::getIsSigned() const
{
	return (this->_is_signed);
}

size_t	AForm::getGradeToSign() const
{
	return (this->_grade_to_sign);
}

size_t	AForm::getGradeToExecute() const
{
	return (this->_grade_to_execute);
}

//!-------------------------------FUNCTIONS-------------------------------------

void	AForm::gradeGuard(size_t grade, int action) const
{
	if (action == TO_SUBMIT)
	{
		if (grade < 1)
			throw (AForm::GradeTooHighException());
		if (grade > 150)
			throw (AForm::GradeTooLowException());
	}
	if (action == TO_SIGN && grade > this->_grade_to_sign)
	{
		throw (AForm::GradeTooLowException());
	}
	if (action == TO_EXECUTE && grade > this->_grade_to_execute)
	{
		throw (AForm::GradeTooLowException());
	}
}

void	AForm::signedGuard(int action) const
{
	if (action == IS_SIGNED && this->_is_signed == true)
		throw (AForm::AlreadySignedException());
	if (action == IS_NOT_SIGNED && this->_is_signed == false)
		throw (AForm::NotSignedException());

}

void	AForm::beSigned(Bureaucrat &b)
{
	this->gradeGuard(b.getGrade(), TO_SIGN);
	this->signedGuard(IS_SIGNED);
	this->_is_signed = true;
}

//!-----------------------------MEMBERS CLASS-------------------------------------

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("grade is too high");
}

const char	*AForm::GradeTooLowException::what() const throw ()
{
	return ("grade is too low");
}

const char	*AForm::AlreadySignedException::what() const throw ()
{
	return ("this form has already been signed");
}

const char	*AForm::NotSignedException::what() const throw ()
{
	return ("this form hasn't been signed");
}
