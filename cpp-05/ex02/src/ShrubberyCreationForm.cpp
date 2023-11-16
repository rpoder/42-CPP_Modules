/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:43:12 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/13 16:28:55 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

//!-------------------------------CONSTRUCTOR-----------------------------------

ShrubberyCreationForm::ShrubberyCreationForm():
	AForm("ShrubberyForm", 145, 137),
	_target("undefined")
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target):
	AForm("ShrubberyForm", 145, 137),
	_target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy):
	AForm("ShrubberyForm", 145, 137)
{
	*this = copy;
}

//!-------------------------------DESTRUCTOR------------------------------------

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

//!-------------------------------OPERATOR--------------------------------------

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	AForm::operator=(copy);
	this->_target = copy.getTarget();
	return(*this);
}

//!-------------------------------ACCCESSORS------------------------------------

const std::string &ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

//!-------------------------------FUNCTIONS-------------------------------------

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	std::ofstream	file;
	std::string		filename(this->_target + "_shrubbery");

	this->signedGuard(IS_NOT_SIGNED);
	this->gradeGuard(executor.getGrade(), TO_EXECUTE);

	file.open(filename.c_str());
	file << std::endl
	<< "                 .              .              ;\%     ;;" << std::endl
	<< "                   ,           ,                :;\%  \%;" << std::endl
	<< "                    :         ;                   :;\%;\'     .," << std::endl
	<< "           ,.        \%;     \%;            ;        \%;\'    ,;" << std::endl
	<< "             ;       ;\%;  \%\%;        ,     \%;    ;\%;    ,\%\'" << std::endl
	<< "              \%;       \%;\%;      ,  ;       \%;  ;\%;   ,\%;\'" << std::endl
	<< "               ;\%;      \%;        ;\%;        \% ;\%;  ,\%;\'" << std::endl
	<< "                \'\%;.     ;\%;     \%;\'         \';\%\%;.\%;\'" << std::endl
	<< "                 \':;\%.    ;\%\%. \%@;        \%; ;@\%;\%\'" << std::endl
	<< "                    \':\%;.  :;bd\%;          \%;@\%;\'" << std::endl
	<< "                      \'@\%:.  :;\%.         ;@@\%;\'" << std::endl
	<< "                        \'@\%.  \';@\%.      ;@@\%;" << std::endl
	<< "                          \'@\%\%. \'@\%\%    ;@@\%;" << std::endl
	<< "                            ;@\%. :@\%\%  \%@@\%;" << std::endl
	<< "                              \%@bd\%\%\%bd\%\%:;" << std::endl
	<< "                                #@\%\%\%\%\%:;;" << std::endl
	<< "                                \%@@\%\%\%::;" << std::endl
	<< "                                \%@@@\%(o);  . \'" << std::endl
	<< "                                \%@@@o\%;:(.,\'" << std::endl
	<< "                            \'.. \%@@@o\%::;" << std::endl
	<< "                               \')@@@o\%::;" << std::endl
	<< "                                \%@@(o)::;" << std::endl
	<< "                               .\%@@@@\%::;" << std::endl
	<< "                               ;\%@@@@\%::;." << std::endl
	<< "                              ;\%@@@@\%\%:;;;." << std::endl
	<< "                          ...;\%@@@@@\%\%:;;;;,.." << std::endl;
	file.close();
}
