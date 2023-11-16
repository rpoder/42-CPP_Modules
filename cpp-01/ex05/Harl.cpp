/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ronanpoder <ronanpoder@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:09:03 by rpoder            #+#    #+#             */
/*   Updated: 2023/02/03 10:33:49 by ronanpoder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

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
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string	choice[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void 		(Harl::*functionPtr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	size_t		i;

	i = 0;
	while (level != choice[i] && i < 4)
		i++;
	if (i > 3)
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	else if (i >= 0 || i <= 3)
		(this->*functionPtr[i])();
	return;
}

