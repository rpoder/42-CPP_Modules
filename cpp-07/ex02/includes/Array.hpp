/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:11:55 by rpoder            #+#    #+#             */
/*   Updated: 2023/04/03 19:14:44 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

template <class T>
class Array
{
	public:
		Array():
			_val(NULL),
			_size(0)
		{};
		Array(unsigned int n):
			_val(new T[n]),
			_size(n)
		{};
		Array(const Array &copy):
			_val(NULL)
		{
			*this = copy;
		}
		~Array()
		{
			delete[] this->_val;
		};

		Array	&operator=(const Array &copy)
		{
			if (this->_val != NULL)
				delete[] _val;
			this->_val = new T[copy.getSize()];
			this->_size = copy.getSize();
			for (unsigned int i = 0; i < copy.getSize(); i++)
				this->_val[i] = copy[i];
			return (*this);
		}

		const T	&operator[](const unsigned int index) const
		{
			if (index >= this->_size || index < 0) {
				throw (outOfBounds());
			}
			return (this->_val[index]);
		}

		T	&operator[](const unsigned int index)
		{
			if (index >= this->_size || index < 0) {
				throw (outOfBounds());
			}
			return (this->_val[index]);
		}

		unsigned int	getSize() const
		{
			return (this->_size);
		}

		unsigned int	size() const
		{
			return (this->_size);
		}

		T	getVal(int i) const
		{
			return (this->_val[i]);
		}

		class outOfBounds:
			public std::exception
		{
			public:
				virtual const char	*what() const throw()
				{
					return ("Array: out of bounds");
				}
		};

	private:
		T				*_val;
		unsigned int	_size;
};

#endif
