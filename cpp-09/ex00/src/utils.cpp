/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   Utils.cpp										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: rpoder <rpoder@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/04/03 18:40:35 by rpoder			#+#	#+#			 */
/*   Updated: 2023/04/03 20:44:59 by rpoder		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "utils.hpp"

const std::string	trimKey(std::string str, char sep)
{
	size_t	i;

	i = str.find(sep);
	if (i == std::string::npos)
		return ("");
	return (str.std::string::substr(0, i));
}

const std::string	trimValue(std::string str, char sep)
{
	size_t	i;

	i = str.find(sep);
	if (i == std::string::npos || !str[i + 1])
		return ("");
	return (str.std::string::substr(i + 1, str.length()));
}

bool isBisextile(int annee) {
	if (annee % 4 != 0) {
		return false;
	} else if (annee % 100 != 0) {
		return true;
	} else if (annee % 400 != 0) {
		return false;
	} else {
		return true;
	}
}

bool isValidDate(std::string date) {
	if (date.length() != 11) {
		return false;
	}
	if (date[4] != '-' || date[7] != '-') {
		return false;
	}
	for (int i = 0; i < 10; i++) {
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(date[i]))
			return false;
	}
	int jour = std::atoi(date.substr(8, 2).c_str());
	int mois = std::atoi(date.substr(5, 2).c_str());
	int annee = std::atoi(date.substr(0, 4).c_str());
	if (mois < 1 || mois > 12)
		return false;
	if (jour < 1)
		return false;
	if (mois == 2)
	{
		if (isBisextile(annee))
		{
			if (jour > 29)
				return false;
		}
		else
		{
			if (jour > 28)
				return false;
		}
	}
	else if (mois == 4 || mois == 6 || mois == 9 || mois == 11)
	{
		if (jour > 30)
			return false;
	}
	else
	{
		if (jour > 31)
			return false;
	}
	return true;
}
