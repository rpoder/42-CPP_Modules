/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:04:33 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/13 16:49:57 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{

	Bureaucrat	b1("Ginette", 150);
	Form		f("Ecologie", 149, 150);

	std::cout << f << std::endl;
	b1.signForm(f);
	b1.signForm(f);
	std::cout << f << std::endl;

	return (0);
}
