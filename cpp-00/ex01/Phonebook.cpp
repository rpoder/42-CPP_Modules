/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:54:37 by ronanpoder        #+#    #+#             */
/*   Updated: 2023/02/02 19:11:09 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

// constructor
Phonebook::Phonebook()
{
	this->contact_nb = 0;
	return ;
}

// destructor
Phonebook::~Phonebook()
{
	return ;
}

void	Phonebook::createContact()
{
	Contact		new_contact;
	std::string	input;

	while (new_contact.getFirstname() == "")
	{
		std::cout << "Firstname: ";
		if (!std::getline(std::cin, input))
			exit(1);
		new_contact.setFirstname(input);
	}
	while (new_contact.getLastname() == "")
	{
		std::cout << "Lastname: ";
		if (!std::getline(std::cin, input))
			exit(1);
		new_contact.setLastname(input);
	}
	while (new_contact.getNickname() == "")
	{
		std::cout << "Nickname: ";
		if (!std::getline(std::cin, input))
			exit(1);
		new_contact.setNickname(input);
	}
	while (new_contact.getPhoneNb() == "")
	{
		std::cout << "Phone number: ";
		if (!std::getline(std::cin, input))
			exit(1);
		new_contact.setPhoneNb(input);
	}
	while (new_contact.getDarkestSecret() == "")
	{
		std::cout << "DargetDarkestSecret: ";
		if (!std::getline(std::cin, input))
			exit(1);
		new_contact.setDarkestSecret(input);
	}
	addContact(new_contact);
}

void	Phonebook::offsetContacts(void)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		this->contacts[i] = this->contacts[i + 1];
		i++;
	}
}

void	Phonebook::addContact(Contact new_contact)
{
	int	id;

	id = 0;
	while (id < this->contact_nb)
		id++;
	if (id == 8)
	{
		this->offsetContacts();
		this->contacts[7] = new_contact;
	}
	else
	{
		this->contact_nb++;
		this->contacts[id] = new_contact;
	}
}

void	Phonebook::showPhonebook()
{
	int			i;
	std::string	input;
	int			id;

	i = 0;
	while (i < contact_nb)
	{
		this->contacts[i].printContactLine(i + 1);
		std::cout << std::endl;
		i++;
	}
	if (i == 0)
	{
		std::cout << "Votre phonebook ne contient aucun contact." << std::endl;
		return ;
	}
	std::cout << "id du contact: ";
	std::getline(std::cin, input);
	if (input.length() == 1)
	{
		id = atoi(input.c_str());
		if ( id > 0 && id <= this->contact_nb)
			this->contacts[id - 1].printContact();
		else
			std::cout << input << " n'est pas un id valide." << std::endl;
	}
	else
		std::cout << input << " n'est pas un id valide." << std::endl;
}

void	Phonebook::searchContact(int id)
{
	if (id > this->contact_nb)
		std::cout << "Ce contact n'existe pas." << std::endl;
	contacts[id].printContact();
	std::cout << std::endl;
}

