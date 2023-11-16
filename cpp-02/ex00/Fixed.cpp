/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ronanpoder <ronanpoder@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:41:33 by rpoder            #+#    #+#             */
/*   Updated: 2023/02/22 18:30:28 by ronanpoder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called." << std::endl;
	this->_raw = 0;
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
	std::cout << "getRawBits() member function called." << std::endl;
	return(this->_raw);
}

void	Fixed::setRawBits(const int raw)
{
	this->_raw = raw;
}

