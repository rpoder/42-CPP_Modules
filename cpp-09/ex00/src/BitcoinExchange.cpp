/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:41:33 by rpoder            #+#    #+#             */
/*   Updated: 2023/04/17 10:16:31 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//!-------------------------------CONSTRUCTOR-----------------------------------

BitcoinExchange::BitcoinExchange(std::string file_path)
{
	std::ifstream		file;
	std::string			str;
	std::string			key;
	std::string			value;

	file.open(file_path.c_str());
	if (file.is_open() == false || file.fail() == true || file.bad() == true)
		throw(ErrorOnOpenException());
	file.peek();
	if (file.fail() == true)
		throw(ErrorOnOpenException());
	std::getline(file, str);
	do {
		std::getline(file, str);
		key = trimKey(str, ',');
		value = trimValue(str, ',');
		if (key.empty() || value.empty())
			throw(BadFileParsingException());
		this->_prices[key + " "] = std::atof(value.c_str());
	} while (file.peek() != EOF);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	*this = copy;
}

//!-------------------------------DESTRUCTOR------------------------------------

BitcoinExchange::~BitcoinExchange()
{

}

//!-------------------------------OPERATOR--------------------------------------

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	this->_prices = copy._prices;
	return(*this);
}

//!-------------------------------ACCESSORS-------------------------------------

//!-------------------------------FUNCTIONS-------------------------------------

void	BitcoinExchange::printPrices()
{
	for (std::map<std::string, double>::iterator it = _prices.begin(); it != _prices.end(); it++)
	{
		std::cout << it->first << " : " << it->second << std::endl;
	}
}

float	BitcoinExchange::computeAtADate(std::string date, float quantity)
{
	std::map<std::string, double>::iterator	it;
	float									btc_value;

	it = _prices.lower_bound(date);
	if (it->first != date)
		it--;
	btc_value = it->second;
	return (btc_value * quantity);
}

void	BitcoinExchange::displayResults(std::string inputs_file_path)
{
	std::ifstream		file;
	std::string			str;
	std::string			key;
	std::string			value;

	file.open(inputs_file_path.c_str());
	if (file.is_open() == false || file.fail() == true || file.bad() == true)
	{
		throw(ErrorOnOpenException());
	}
	file.peek();
	if (file.fail() == true)
	{
		throw(ErrorOnOpenException());
	}
	std::getline(file, str);
	do {
		std::getline(file, str);
		if (str.length() == 0)
			continue ;
		key = trimKey(str, '|');
		value = trimValue(str, '|');
		try
		{
			BitcoinExchange::paramsGuard(str, key, value);
			std::cout << key << " -> " << value << " =	";
			std::cout << this->computeAtADate(key, std::atof(value.c_str())) << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << "Error:	"<< e.what() << std::endl;
		}

	} while (file.peek() != EOF);
}


void	BitcoinExchange::paramsGuard(std::string str, std::string key, std::string value)
{
	if ( key.empty() || value.empty() || !isValidDate(key))
		throw(ParsingErrorException("bad input => " + str));
	if (std::atof(value.c_str()) < 0)
		throw(ParsingErrorException("not a positive number"));
	if (std::atof(value.c_str()) > 1000)
		throw(ParsingErrorException("too large number"));
}
