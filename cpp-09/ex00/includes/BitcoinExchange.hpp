/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:41:22 by rpoder            #+#    #+#             */
/*   Updated: 2023/04/06 17:54:41 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <algorithm>
#include <map>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <string>

#include "utils.hpp"
#include "Exceptions.hpp"

class BitcoinExchange
{
	public:
		BitcoinExchange(std::string file_path);
		BitcoinExchange(const BitcoinExchange &copy);
		~BitcoinExchange();

		BitcoinExchange	&operator=(const BitcoinExchange &copy);

		void			printPrices();
		float			computeAtADate(std::string date, float quantity);
		void			displayResults(std::string inputs_file_path);

	private:
		void			paramsGuard(std::string str, std::string key, std::string value);
		BitcoinExchange();

		std::map<std::string, double>	_prices;
};

#endif

