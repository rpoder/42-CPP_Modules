/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:43:46 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/13 12:47:12 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
#include <stdlib.h>
# include <time.h>


class RobotomyRequestForm:
	virtual public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		virtual	~RobotomyRequestForm();

		RobotomyRequestForm	&operator=(const RobotomyRequestForm &copy);

		const std::string &getTarget() const;

		virtual void	execute(const Bureaucrat &executor) const;

	private:
		std::string	_target;
};

#endif
