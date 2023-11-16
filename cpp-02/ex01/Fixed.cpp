/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:41:33 by rpoder            #+#    #+#             */
/*   Updated: 2023/02/28 18:25:34 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called." << std::endl;
	this->_raw = 0;
}

Fixed::Fixed(const int raw)
{
	std::cout << "Int constructor called." << std::endl;
	if (this->isValidInt(raw) == false)
	{
		this->_raw = 0;
	}
	else {
		this->_raw = raw << this->_bits_number;
	}
}

Fixed::Fixed(const float raw)
{
	std::cout << "Float constructor called." << std::endl;
	if (this->isValidFloat(raw) == false)
	{
		this->_raw = 0;
	}
	else {
		this->_raw = roundf(raw * (1 << this->_bits_number));
	}
}

Fixed::~Fixed()
{
	std::cout << "Destructor called." << std::endl;
}

Fixed::Fixed(const Fixed &rhs)
{
	std::cout << "Copy constructor called." << std::endl;
	*this = rhs;
}

// operator overloads
void Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called." << std::endl;
	_raw = rhs.getRawBits();
}

// accessors & mutators
int	Fixed::getRawBits(void) const
{
	return(this->_raw);
}

void	Fixed::setRawBits(const int raw)
{
	if (this->isValidInt(raw) == false)
	{
		this->_raw = 0;
	}
	else {
		this->_raw = raw;
	}
}

// methods
int	Fixed::toInt(void) const
{
	return (this->_raw >> this->_bits_number);
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_raw / (float)(1 << this->_bits_number));
}

bool	Fixed::isValidInt(const int num) const
{
	if (num > U23_INT_MAX)
	{
		std::cout
		<< "ERR:	You cannot create a fixed point with an int > to 8388607."
		<< std::endl;
		return (false);
	}
	else if (num < U23_INT_MIN)
	{
		std::cout
		<< "ERR:	You cannot create a fixed point with an int < to -8388608."
		<< std::endl;
		return (false);
	}
	else{
		return (true);
	}
}

bool	Fixed::isValidFloat(const float num) const
{
	if (num > U23_FLOAT_MAX - 2)
	{
		std::cout
		<< "ERR:	You cannot create a fixed point with an float > to 8388605.0."
		<< std::endl;
		return (false);
	}
	else if (num < U23_FLOAT_MIN + 2)
	{
		std::cout
		<< "ERR:	You cannot create a fixed point with an float < to -8388606.0."
		<< std::endl;
		return (false);
	}
	else{
		return (true);
	}
}

// NOT PART OF THE CLASS
// Stream operator overloads
std::ostream	&operator<<(std::ostream &os, const Fixed &rhs)
{
	std::cout << rhs.toFloat();
	return (os);
}
