/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:43:46 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/13 12:47:12 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm:
	virtual public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		virtual	~PresidentialPardonForm();

		PresidentialPardonForm	&operator=(const PresidentialPardonForm &copy);

		const std::string &getTarget() const;

		virtual void	execute(const Bureaucrat &executor) const;

	private:
		std::string	_target;
};

#endif
