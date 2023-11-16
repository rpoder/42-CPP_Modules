/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:08:33 by ronanpoder        #+#    #+#             */
/*   Updated: 2022/12/04 12:55:41 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// constructor
Contact::Contact()
{
	return ;
}

// destructor
Contact::~Contact()
{
	return ;
}

void	Contact::printContact() const
{
	std::cout << "Firstname:	" + this->firstname << std::endl;
	std::cout << "Lastname:	" + this->lastname << std::endl;
	std::cout << "Nickname:	" + this->nickname << std::endl;
	std::cout << "Phone:	" + this->phoneNb << std::endl;
	std::cout << "Darkest Secret:	" + this->darkestSecret << std::endl;
}

static	std::string trimString(std::string str)
{
	int			i;
	std::string	dst;

	dst.resize(str.length());
	i = 0;
	while (str[i] && i < 10)
	{
		dst[i] = str[i];
		i++;
	}
	if (str.length() > 10)
		dst[9] = '.';
	return (dst);
}

void	Contact::printContactLine(int i) const
{
	std::cout << std::setw(10);
	std::cout << i;
	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << trimString(this->firstname);
	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << trimString(this->lastname);
	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << trimString(this->nickname);
}

// setters
void	Contact::setFirstname(std::string firstname)
{
	this->firstname = firstname;
}

void	Contact::setLastname(std::string lastname)
{
	this->lastname = lastname;
}

void	Contact::setNickname(std::string nickname)
{
	this->nickname = nickname;
}

void	Contact::setPhoneNb(std::string phoneNb)
{
	this->phoneNb = phoneNb;
}

void	Contact::setDarkestSecret(std::string darkestSecret)
{
	this->darkestSecret = darkestSecret;
}


// getters

std::string	Contact::getFirstname(void) const
{
	return (this->firstname);
}

std::string	Contact::getLastname(void) const
{
	return (this->lastname);
}

std::string	Contact::getNickname(void) const
{
	return (this->nickname);
}

std::string	Contact::getPhoneNb(void) const
{
	return (this->phoneNb);
}

std::string	Contact::getDarkestSecret(void) const
{
	return (this->darkestSecret);
}
