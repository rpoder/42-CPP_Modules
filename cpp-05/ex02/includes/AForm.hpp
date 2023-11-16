/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:52:39 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/13 11:31:58 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# define TO_SIGN		1
# define TO_EXECUTE		2
# define TO_SUBMIT		3
# define IS_SIGNED		4
# define IS_NOT_SIGNED	5

# include <iostream>

class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(std::string name, size_t grade_to_sign, size_t grade_to_execute);
		AForm(const AForm &copy);
		virtual	~AForm();

		AForm	&operator=(const AForm &copy);

		std::string		getName() const;
		bool			getIsSigned() const;
		size_t			getGradeToSign() const;
		size_t			getGradeToExecute() const;

		void			beSigned(Bureaucrat &b);
		virtual void	execute(const Bureaucrat &executor) const = 0;

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
		class NotSignedException:
			public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		void				gradeGuard(size_t grade, int action) const;
		void				signedGuard(int action) const;

	private:
		const std::string	_name;
		bool				_is_signed;
		const size_t		_grade_to_sign;
		const size_t		_grade_to_execute;
};

std::ostream	&operator<<(std::ostream& os, AForm &f);

#endif
