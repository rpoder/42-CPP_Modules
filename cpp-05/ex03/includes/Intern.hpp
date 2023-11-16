/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ronanpoder <ronanpoder@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:07:09 by ronanpoder        #+#    #+#             */
/*   Updated: 2023/03/14 12:16:39 by ronanpoder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &copy);
		~Intern();

		Intern	&operator=(const Intern &copy);

		AForm 		*makeForm(std::string form, std::string target);

	private:
		AForm		*makeShrubberyCreationForm(std::string target) const;
		AForm		*makeRobotomyRequestForm(std::string target) const;
		AForm		*makePresidentialPardonForm(std::string target) const;
};

#endif
