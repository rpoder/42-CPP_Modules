/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:52:39 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/13 16:37:06 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# define TO_SIGN	1
# define TO_EXECUTE	2
# define TO_SUBMIT	3

# include <iostream>

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(std::string name, size_t grade_to_sign, size_t grade_to_execute);
		Form(const Form &copy);
		~Form();

		Form	&operator=(const Form &copy);

		std::string	getName() const;
		bool		getIsSigned() const;
		size_t		getGradeToSign() const;
		size_t		getGradeToExecute() const;

		void	beSigned(Bureaucrat &b);

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
		class AlreadySignedException:
			public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

	private:
		const std::string	_name;
		bool				_is_signed;
		const size_t		_grade_to_sign;
		const size_t		_grade_to_execute;
		void				gradeGuard(size_t grade, int action) const;
		void				signedGuard();
};

std::ostream	&operator<<(std::ostream& os, Form f);

#endif
