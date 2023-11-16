/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:06:06 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/10 16:05:49 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>


# include "Form.hpp"

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const std::string &name, size_t grade);
		Bureaucrat(const Bureaucrat &copy);
		~Bureaucrat();

		Bureaucrat	&operator=(const Bureaucrat &copy);

		const std::string	&getName(void) const;
		size_t				getGrade(void) const;

		void				upgrade();
		void				downgrade();
		void				signForm(Form &f);

		class GradeTooHighException:
			public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		class GradeTooLowException:
			public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

	private:
		const std::string	_name;
		size_t				_grade;

		void				gradeGuard(size_t grade) const;
};

std::ostream	&operator<<(std::ostream& os, Bureaucrat b);

#endif
