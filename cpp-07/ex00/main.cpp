/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:28:40 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/31 12:50:59 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int	main()
{
	std::string	s1;
	std::string	s2;
	int			i1 = 10;
	int			i2 = -10;

	s1 = "arg1";
	s2 = "arg2";

	std::cout << s1 << " " << s2 << std::endl;
	::swap(s1, s2);
	std::cout << s1 << " " << s2 << std::endl;

	std::cout << ::min(i1, i2) << std::endl;
	std::cout << ::max(i1, i2) << std::endl;

	return (0);
}
