/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:41:33 by rpoder            #+#    #+#             */
/*   Updated: 2023/02/28 18:23:22 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->_raw = 0;
}

Fixed::Fixed(const int raw)
{
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
	if (this->isValidFloat(raw) == false)
	{
		this->_raw = 0;
	}
	else {
		this->_raw = roundf(raw * (1 << this->_bits_number));
	}}

Fixed::~Fixed()
{}

Fixed::Fixed(const Fixed &rhs)
{
	*this = rhs;
}

// operator overloads
void	Fixed::operator=(const Fixed &rhs)
{
	_raw = rhs.getRawBits();
}

bool	Fixed::operator<(const Fixed &rhs)
{
	return (this->toFloat() < rhs.toFloat());
}

bool	Fixed::operator>(const Fixed &rhs)
{
	return (this->toFloat() > rhs.toFloat());
}

bool	Fixed::operator<=(const Fixed &rhs)
{
	return (this->toFloat() <= rhs.toFloat());
}

bool	Fixed::operator>=(const Fixed &rhs)
{
	return (this->toFloat() >= rhs.toFloat());
}

bool	Fixed::operator==(const Fixed &rhs)
{
	return (this->toFloat() == rhs.toFloat());
}

bool	Fixed::operator!=(const Fixed &rhs)
{
	return (this->toFloat() != rhs.toFloat());
}

Fixed	Fixed::operator+(const Fixed &rhs)
{
	Fixed ret(this->toFloat() + rhs.toFloat());

	return (ret);
}

Fixed	Fixed::operator-(const Fixed &rhs)
{
	Fixed ret(this->toFloat() - rhs.toFloat());

	return (ret);
}

Fixed	Fixed::operator*(const Fixed &rhs)
{
	Fixed ret(this->toFloat() * rhs.toFloat());

	return (ret);
}

Fixed	Fixed::operator/(const Fixed &rhs)
{
	Fixed ret(this->toFloat() / rhs.toFloat());

	return (ret);
}

Fixed Fixed::operator++()
{
	Fixed tmp;

	tmp.setRawBits(1);
	*this = *this + tmp;
	return (*this);
}

Fixed Fixed::operator--()
{
	Fixed tmp;

	tmp.setRawBits(1);
	*this = *this - tmp;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp;
	Fixed ret(*this);

	tmp.setRawBits(1);
	*this = *this + tmp;
	return (ret);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp;
	Fixed ret(*this);

	tmp.setRawBits(1);
	*this = *this + tmp;
	return (ret);
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

Fixed	Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1._raw < f2._raw)
		return (f1);
	else
		return (f2);
}

Fixed	Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if (f1._raw < f2._raw)
		return (f1);
	else
		return (f2);
}


Fixed	Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1._raw > f2._raw)
		return (f1);
	else
		return (f2);
}

Fixed	Fixed::max(const Fixed &f1, const Fixed &f2)
{
	if (f1._raw > f2._raw)
		return (f1);
	else
		return (f2);
}


bool	Fixed::isValidInt(const int num) const
{
	if (num > 8388607)
	{
		std::cout
		<< "ERR:	You cannot create a fixed point with an int > to 8388607."
		<< std::endl;
		return (false);
	}
	else if (num < -8388608)
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
