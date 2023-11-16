/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ronanpoder <ronanpoder@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:22:28 by rpoder            #+#    #+#             */
/*   Updated: 2023/02/22 18:30:16 by ronanpoder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FIXED_HPP_
# define _FIXED_HPP_

#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &rhs);
		~Fixed();

		void operator=(const Fixed &rhs);

		int		getRawBits(void) const;
		void	setRawBits(const int raw);

	private:
		int					_raw;
		static const int	_bits_number = 8;
};

#endif
