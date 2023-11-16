/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:53:58 by ronanpoder        #+#    #+#             */
/*   Updated: 2023/04/10 09:54:42 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

//!---------------------------CONSTRUCTORS--------------------------------------

Span::Span(unsigned int n):
	_size(n)
{
	// if (n <= 0)
	// 	throw (Span::WrongConstructorParametersException());
	this->_tab.reserve(n);
}

Span::Span(const Span &copy)
{
	*this = copy;
}

//!-------------------------------DESTRUCTOR------------------------------------

Span::~Span()
{

}

//!-------------------------------OPERATOR--------------------------------------

Span	&Span::operator=(const Span &copy)
{
	this->_size = copy.getSize();
	this->_tab = copy._tab;
	return(*this);
}

//!-------------------------------ACCESSORS-------------------------------------

unsigned int	Span::getSize() const
{
	return (this->_size);
}


//!-------------------------------FUNCTIONS-------------------------------------

void	Span::addNumber(int number)
{
	if ( _size == 0 || _tab.size() > _size - 1)
		throw (Span::VectorIsFullException());
	this->_tab.push_back(number);
}

void	Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_tab.size() + std::distance(begin, end) > _size)
		throw (Span::TooMuchNumbers());
	_tab.insert(_tab.end(), begin, end);
}

int	Span::shortestSpan()
{
	std::vector<int>	tmp;
	int					shortest;

	if (_tab.size() <= 1)
		throw (Span::CannotCallFunctionException());
	tmp = _tab;
	std::sort(tmp.begin(), tmp.end());
	shortest = this->longestSpan();
	for (std::vector<int>::iterator it = tmp.begin(); it < tmp.end() - 1 ; it++)
	{
		if (abs(*it - (*(it + 1))) < shortest)
			shortest = abs(*it - (*(it + 1)));
	}
	return (shortest);
}

int	Span::longestSpan()
{
	std::vector<int>::iterator	max;
	std::vector<int>::iterator	min;

	if (_tab.size() <= 1)
		throw (Span::CannotCallFunctionException());
	max = std::max_element(_tab.begin(), _tab.end());
	min = std::min_element(_tab.begin(), _tab.end());
	return (*max - *min);
}

//!-------------------------------CLASSES--------------------------------------

const char	*Span::VectorIsFullException::what() const throw()
{
	return ("Vector: No more space");
}

const char	*Span::WrongConstructorParametersException::what() const throw()
{
	return ("Vector: Wrong constructor parameters");
}

const char	*Span::CannotCallFunctionException::what() const throw()
{
	return ("Cannot call function");
}

const char	*Span::TooMuchNumbers::what() const throw()
{
	return ("Vector: Too much numbers");
}
