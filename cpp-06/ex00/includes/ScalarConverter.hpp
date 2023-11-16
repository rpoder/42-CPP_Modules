/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:10:32 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/26 14:21:53 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cctype>
# include <clocale>
# include <climits>
# include <cstdlib>
# include <iomanip>
# include <limits>


# define TYPE_UNDEFINED	0
# define TYPE_CHAR		1
# define TYPE_INT		2
# define TYPE_FLOAT		3
# define TYPE_DOUBLE	4
# define TYPE_INF_POS	5
# define TYPE_INF_NEG	6
# define TYPE_NAN		7
# define TYPE_INFF_POS	8
# define TYPE_INFF_NEG	9
# define TYPE_NANF		10


class ScalarConverter
{
	public:
		static void	convert(const std::string &str);

		class WrongParameterException:
			public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class OverflowException:
			public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

	private:
		static int	typeExtractor(const std::string &str);
		static int	specialTypeExtractor(const std::string &str);
		static void	display_char(const std::string &str);
		static void	display_int(const std::string &str);
		static void	display_float(const std::string &str);
		static void	display_double(const std::string &str);
		static void	display_limits(const int lim_type);
		static void	display_nan();
		static bool	isdigitstr(const std::string &str, size_t start, size_t stop);
		static bool	isOverflowing(const std::string &str, int type);



};

#endif
