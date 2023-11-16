/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:29:20 by rpoder            #+#    #+#             */
/*   Updated: 2023/04/03 20:39:34 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <iostream>

class ErrorOnOpenException:
	public std::exception
{
	public:
		const char *what() const throw();
};
class BadFileParsingException:
	public std::exception
{
	public:
		const char *what() const throw();
};

class ParsingErrorException:
	public std::exception
{
	public:
		ParsingErrorException(std::string error) throw();
		virtual ~ParsingErrorException() throw();
		const char *what() const throw();

	private:
		std::string	_error;
};

#endif
