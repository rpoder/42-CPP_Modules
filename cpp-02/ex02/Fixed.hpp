/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:22:28 by rpoder            #+#    #+#             */
/*   Updated: 2023/02/28 18:07:14 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FIXED_HPP_
# define _FIXED_HPP_

#include <iostream>
#include <cmath>
#include <bitset>

#define U23_INT_MAX 8388607
#define U23_INT_MIN -8388608
#define U23_FLOAT_MAX 8388607.0
#define U23_FLOAT_MIN -8388608.0

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &rhs);
		Fixed(const int num);
		Fixed(const float num);
		~Fixed();

		void 			operator=(const Fixed &rhs);
		bool			operator<(const Fixed &rhs);
		bool			operator>(const Fixed &rhs);
		bool			operator<=(const Fixed &rhs);
		bool			operator>=(const Fixed &rhs);
		bool			operator==(const Fixed &rhs);
		bool			operator!=(const Fixed &rhs);
		Fixed			operator+(const Fixed &rhs);
		Fixed			operator-(const Fixed &rhs);
		Fixed			operator*(const Fixed &rhs);
		Fixed			operator/(const Fixed &rhs);
		Fixed 			operator++();
		Fixed 			operator++(int);
		Fixed 			operator--();
		Fixed 			operator--(int);


		int				getRawBits(void) const;
		void			setRawBits(const int raw);

		float			toFloat( void ) const;
		int				toInt( void ) const;
		static Fixed	min(Fixed &f1, Fixed &f2);
		static Fixed	min(const Fixed &f1, const Fixed &f2);
		static Fixed	max(Fixed &f1, Fixed &f2);
		static Fixed	max(const Fixed &f1, const Fixed &f2);

	private:
		int					_raw;
		static const int	_bits_number = 8;
		bool				isValidInt(const int num) const;
		bool				isValidFloat(const float num) const;
};

std::ostream	&operator<<(std::ostream &os, const Fixed &rhs);


#endif
