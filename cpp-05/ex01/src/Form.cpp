/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:53:44 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/13 16:44:17 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

//!-------------------------------CONSTRUCTOR-----------------------------------

Form::Form():
	_name("undefined"),
	_is_signed(false),
	_grade_to_sign(150),
	_grade_to_execute(150)
{

}

Form::Form(std::string name, size_t grade_to_sign, size_t grade_to_execute):
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

Form::Form(const Form &copy):
	_grade_to_sign(150),
	_grade_to_execute(150)
{
	*this = copy;
}

//!-------------------------------DESTRUCTOR------------------------------------

Form::~Form()
{

}

//!-------------------------------OPERATOR--------------------------------------

Form	&Form::operator=(const Form &copy)
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

std::ostream	&operator<<(std::ostream& os, Form f)
{
	std::cout << "------------FORM " << f.getName() << std::endl;
	std::cout << "is_signed: " << f.getIsSigned() << std::endl;
	std::cout << "minimum grade to sign: " << f.getGradeToSign() << std::endl;
	std::cout << "minimum grade to execute: " << f.getGradeToExecute() << std::endl;
	return (os);
}

//!-------------------------------ACCESSORS-------------------------------------

std::string	Form::getName() const
{
	return (this->_name);
}

bool	Form::getIsSigned() const
{
	return (this->_is_signed);
}

size_t	Form::getGradeToSign() const
{
	return (this->_grade_to_sign);
}

size_t	Form::getGradeToExecute() const
{
	return (this->_grade_to_execute);
}

//!-------------------------------FUNCTIONS-------------------------------------

void	Form::gradeGuard(size_t grade, int action) const
{
	if (action == TO_SUBMIT)
	{
		if (grade < 1)
			throw (Form::GradeTooHighException());
		if (grade > 150)
			throw (Form::GradeTooLowException());
	}
	if (action == TO_SIGN && grade > this->_grade_to_sign)
	{
		throw (Form::GradeTooLowException());
	}
	if (action == TO_EXECUTE && grade > this->_grade_to_execute)
	{
		throw (Form::GradeTooLowException());
	}
}

void	Form::signedGuard()
{
	if (this->_is_signed == true)
		throw (Form::AlreadySignedException());
}

void	Form::beSigned(Bureaucrat &b)
{
	this->gradeGuard(b.getGrade(), TO_SIGN);
	this->signedGuard();
	this->_is_signed = true;
}

//!-----------------------------MEMBERS CLASS-------------------------------------

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("grade is too high");
}

const char	*Form::GradeTooLowException::what() const throw ()
{
	return ("grade is too low");
}

const char	*Form::AlreadySignedException::what() const throw ()
{
	return ("this form has already been signed");
}
