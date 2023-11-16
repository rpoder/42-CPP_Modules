/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:13:32 by ronanpoder        #+#    #+#             */
/*   Updated: 2023/02/05 15:01:09 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	main(void)
{
	Phonebook	book;
	Contact		new_contact;
	std::string	input;

	std::cout << "Bienvenue sur votre Phonebook" << std::endl;
	while (true)
	{
		std::cout << "> ";
		if (!std::getline(std::cin, input))
			return (0);
		if (input == "ADD")
			book.createContact();
		else if (input == "SEARCH")
			book.showPhonebook();
		else if (input == "EXIT")
			return (0);
		else
			std::cout << input + ": command not found" << std::endl;
	}
}
