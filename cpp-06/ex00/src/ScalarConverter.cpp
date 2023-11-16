/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:10:15 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/26 14:49:30 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

//!-------------------------------FUNCTIONS-------------------------------------

bool	ScalarConverter::isdigitstr(const std::string &str, size_t start, size_t stop)
{
	for (; start < stop; start++)
	{
		if (!std::isdigit(str[start]))
			return (false);
	}
	return (true);
}

bool	ScalarConverter::isOverflowing(const std::string &str, int type)
{
	double	res;
	float	res_f;

	res = std::atof(str.c_str());
	if (type == TYPE_INT)
	{
		if (res < INT_MIN || res > INT_MAX)
			return (true);
	}
	else if (type == TYPE_FLOAT)
	{
		res_f = static_cast<float>(res);
		if (res_f == std::numeric_limits<float>::infinity() ||
			res_f == -std::numeric_limits<float>::infinity())
			return (true);
	}
	else if (type == TYPE_DOUBLE)
	{
		if (res == std::numeric_limits<double>::infinity() ||
			res == -std::numeric_limits<double>::infinity())
			return (true);
	}
	return (false);
}

int	ScalarConverter::specialTypeExtractor(const std::string &str)
{
	if (str.compare("inf") == 0 || str.compare("+inf") == 0)
		return (TYPE_INF_POS);
	else if (str.compare("-inf") == 0)
		return (TYPE_INF_NEG);
	else if (str.compare("inff") == 0 || str.compare("+inff") == 0)
		return (TYPE_INFF_POS);
	else if (str.compare("-inff") == 0)
		return (TYPE_INFF_NEG);
	else if (str.compare("nan") == 0)
		return (TYPE_NAN);
	else if (str.compare("nanf") == 0)
		return (TYPE_NANF);
	else
		return (TYPE_UNDEFINED);
}

int	ScalarConverter::typeExtractor(const std::string &str)
{
	size_t	i;
	size_t	pos;
	int		special_type;

	special_type = specialTypeExtractor(str);
	if (special_type != TYPE_UNDEFINED)
		return (special_type);
	i = 0;
	if (str[i] == '-')
		i++;
	pos = str.find('.', i);
	if (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
		return (TYPE_CHAR);
	else if (pos != std::string::npos && pos != 0)
	{
		if (isdigitstr(str, i, pos))
		{
			if (isdigitstr(str, pos + 1, str.length() - 1))
			{
				if (str[str.length() - 1] == 'f')
					return (TYPE_FLOAT);
				else if (std::isdigit(str[str.length() - 1]))
					return (TYPE_DOUBLE);
			}
		}
	}
	else
	{
		if (isdigitstr(str, i, str.length()))
			return (TYPE_INT);
	}
	return (TYPE_UNDEFINED);
}

void	ScalarConverter::display_limits(const int lim_type)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (lim_type == TYPE_INF_POS || lim_type == TYPE_INFF_POS)
	{
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
	}
	else if (lim_type == TYPE_INF_NEG || lim_type == TYPE_INFF_NEG)
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

void	ScalarConverter::display_nan()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossibile" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

void	ScalarConverter::display_char(const std::string &str)
{
	unsigned char	c;

	c = str[0];
	std::cout <<
	"char: " << str << std::endl <<
	"int: " << static_cast<int>(c) << std::endl <<
	"float: " << static_cast<float>(c) << ".0f" << std::endl <<
	"double: " << static_cast<double>(c) << ".0" << std::endl;
}

void	ScalarConverter::display_int(const std::string &str)
{
	int	num;

	num = std::atoi(str.c_str());
	if (num < -126 || num > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(num))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(num) << std::endl;
	std::cout << "int: " << num << std::endl;
	std::cout << std::fixed;
	std::cout << "float: " << std::setprecision(2) << static_cast<float>(num) <<  "f" << std::endl;
	std::cout << std::fixed;
	std::cout << "double: " << std::setprecision(2) << static_cast<double>(num) << std::endl;
}

void	ScalarConverter::display_float(const std::string &str)
{
	double	num;

	num = std::atof(str.c_str());
	if (num < -126 || num > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(num))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(num) << std::endl;
	if (isOverflowing(str, TYPE_INT) == true)
		std::cout << "int: overflow" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(num)  << std::endl;
	std::cout << std::fixed;
	std::cout << "float: " << std::setprecision(2) << static_cast<float>(num) <<  "f" << std::endl;
	std::cout << std::fixed;
	std::cout << "double: " << std::setprecision(2) << num << std::endl;
}

void	ScalarConverter::display_double(const std::string &str)
{
	double	num;

	num = std::atof(str.c_str());
	if (num < -126 || num > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(num))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(num) << std::endl;
	if (isOverflowing(str, TYPE_INT) == true)
		std::cout << "int: overflow" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(num)  << std::endl;
	if (isOverflowing(str, TYPE_FLOAT) == true)
	{
		std::cout << "float: overflow" << std::endl;
	}
	else
	{
		std::cout << std::fixed;
		std::cout << "float: " << std::setprecision(2) << static_cast<float>(num) <<  "f" << std::endl;
	}
	std::cout << std::fixed;
	std::cout << "double: " << std::setprecision(2) << num << std::endl;
}

void	ScalarConverter::convert(const std::string &str)
{
	int	type = typeExtractor(str);
	if (type == TYPE_UNDEFINED)
		throw (ScalarConverter::WrongParameterException());
	if (type == TYPE_INF_POS || type == TYPE_INF_NEG ||
		type == TYPE_INFF_POS || type == TYPE_INFF_NEG)
	{
		display_limits(type);
		return ;
	}
	if (type == TYPE_NAN || type == TYPE_NANF)
	{
		display_nan();
		return ;
	}
	if (isOverflowing(str, type) == true)
		throw (ScalarConverter::OverflowException());
	switch (type)
	{
		case TYPE_CHAR:
			display_char(str);
			break;
		case TYPE_INT:
			display_int(str);
			break;
		case TYPE_FLOAT:
			display_float(str);
			break;
		case TYPE_DOUBLE:
			display_double(str);
			break;
	}
}

//!-------------------------------EXCEPTION-------------------------------------

const char	*ScalarConverter::WrongParameterException::what() const throw ()
{
	return ("ERR:	Wrong parameter. Please insert a char, int, float or double formated like in the subject.");
}

const char	*ScalarConverter::OverflowException::what() const throw ()
{
	return ("ERR:	Overflow, please reduce your expectations :)");
}
