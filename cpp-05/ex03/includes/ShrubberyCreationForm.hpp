/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:43:46 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/13 16:15:12 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

#include <fstream>


class ShrubberyCreationForm:
	virtual public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		virtual	~ShrubberyCreationForm();

		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &copy);

		const std::string &getTarget() const;

		virtual void	execute(const Bureaucrat &executor) const;

	private:
		std::string	_target;
};

#endif
