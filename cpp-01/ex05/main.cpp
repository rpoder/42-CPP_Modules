/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:09:03 by rpoder            #+#    #+#             */
/*   Updated: 2023/02/21 13:38:27 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl	h1;

	h1.complain("");
	h1.complain("DEBUG");
	h1.complain("INFO");
	h1.complain("WARNING");
	h1.complain("ERROR");

	return(0);
}
