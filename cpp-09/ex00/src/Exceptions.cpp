/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:31:42 by rpoder            #+#    #+#             */
/*   Updated: 2023/04/17 10:08:46 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

ParsingErrorException::ParsingErrorException(std::string error) throw():
	std::exception(),
	_error(error)
{
}

ParsingErrorException::~ParsingErrorException() throw()
{
}

const char	*ParsingErrorException::ParsingErrorException::what() const throw()
{
	return (this->_error.c_str());
}

const char	*ErrorOnOpenException::what() const throw()
{
	return ("could not open file.");
}

const char	*BadFileParsingException::what() const throw()
{
	return ("cannot read file.");
}
