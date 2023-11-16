/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ronanpoder <ronanpoder@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:21:29 by rpoder            #+#    #+#             */
/*   Updated: 2023/02/24 10:13:14 by ronanpoder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "---------------------------" << std::endl;
	std::cout << "INCREMENTATIONS" << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;

	std::cout << "---------------------------" << std::endl;
	std::cout << "MIN MAX" << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "---------------------------" << std::endl;
	std::cout << "CHECK OPERATEUR COMPARAISON" << std::endl;
	std::cout << (a == b) << std::endl;
	a = b;
	std::cout << (a == b) << std::endl;

	return (0);
}
