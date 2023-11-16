/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:56:37 by ronanpoder        #+#    #+#             */
/*   Updated: 2023/04/06 19:23:04 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include <iostream>

class Span
{
	public:
		Span(unsigned int n);
		Span(const Span &copy);
		~Span();

		Span			&operator=(const Span &copy);

		unsigned int		getSize() const;
		void				addNumber(int number);
		void				addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int					longestSpan();
		int					shortestSpan();
		std::vector<int>	_tab;

	private:
		Span();
		unsigned int		_size;

		class VectorIsFullException:
			public std::exception
		{
			public:
				const char	*what() const throw();
		};
		class WrongConstructorParametersException:
			public std::exception
		{
			public:
				const char	*what() const throw();
		};
		class CannotCallFunctionException:
			public std::exception
		{
			public:
				const char	*what() const throw();
		};
		class TooMuchNumbers:
			public std::exception
		{
			public:
				const char	*what() const throw();
		};
};

template <typename T>
void	printContainer(T container)
{
	std::cout << "Container --------" << std::endl;
	for (typename T::iterator it = container.begin(); it != container.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "------------------" << std::endl;

}

#endif
