/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HarlFilter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:09:03 by rpoder            #+#    #+#             */
/*   Updated: 2023/02/16 13:39:44 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HarlFilter.hpp"

Harl::Harl()
{
	return ;
}

Harl::~Harl()
{
	return ;
}

void	Harl::debug(void)
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month." << std::endl << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string	choice[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void 		(Harl::*functionPtr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	size_t		i;

	i = 0;
	while (level != choice[i] && i < 4)
		i++;

	switch(i)
	{
		case(0):
		{
			(this->*functionPtr[0])();
		}
		case(1):
		{
			(this->*functionPtr[1])();
		}
		case(2):
		{
			(this->*functionPtr[2])();

		}
		case(3):
		{
			(this->*functionPtr[3])();
			break ;
		}
		default:
		{
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break ;
		}
	}
}

