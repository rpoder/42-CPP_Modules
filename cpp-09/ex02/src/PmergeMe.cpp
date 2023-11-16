/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   PmergeMe.cpp									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: rpoder <rpoder@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/04/04 17:46:49 by rpoder			#+#	#+#			 */
/*   Updated: 2023/04/04 18:18:21 by rpoder		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "PmergeMe.hpp"

//!-------------------------------CONSTRUCTOR-----------------------------------

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	*this = copy;
}

//!-------------------------------DESTRUCTOR------------------------------------

PmergeMe::~PmergeMe()
{

}

//!-------------------------------OPERATOR--------------------------------------

PmergeMe	&PmergeMe::operator=(const PmergeMe &copy)
{
	_Xvector = copy._Xvector;
	_Svector = copy._Svector;
	_min_element_vector = copy._min_element_vector;
	_Xdeque = copy._Xdeque;
	_Sdeque = copy._Sdeque;
	_min_element_deque = copy._min_element_deque;
	return(*this);
}

//!-------------------------------FUNCTIONS-------------------------------------

void	PmergeMe::createPairs(std::vector<int> tab)
{
	for (std::vector<int>::iterator it = tab.begin(); it != tab.end(); it++)
	{
		if (it != tab.end() && it + 1 != tab.end())
		{
			std::pair<int, int>	tmp(*it, *(it + 1));
			_Xvector.push_back(tmp);
			it++;
		}
		else
		{
			std::pair<int, int>	tmp(-1, *it);
			_Xvector.push_back(tmp);
		}
	}
}

void	PmergeMe::sortPairs(std::vector<std::pair<int, int> > &container)
{
	for (std::vector<std::pair<int, int> >::iterator it = container.begin(); it != container.end(); it++)
	{
		if ( it->first > it->second)
		{
			std::swap(it->first, it->second);
		}
	}
}

std::pair<int, int>	PmergeMe::getPair(std::vector<std::pair<int, int> > tab, int second)
{
	for (std::vector<std::pair<int, int> >::iterator it = tab.begin(); it != tab.end(); it++)
	{
		if (it->second == second)
		{
			return (*it);
		}
	}
	return (std::pair<int, int> (-1, -1));
}

void	PmergeMe::createAndSort_Svector(std::vector<std::pair<int, int> > &container)
{
	int					min;
	std::pair<int, int>	pair;

	for (std::vector<std::pair<int, int> >::iterator it = container.begin(); it != container.end(); it++)
	{
		if (it->first != -1)
			_Svector.push_back(it->second);
	}
	std::sort(_Svector.begin(), _Svector.end());
	min = *std::min_element(_Svector.begin(), _Svector.end());
	_min_element_vector = getPair(container, min).first;
	_Svector.insert(_Svector.begin(), _min_element_vector);
}

void	PmergeMe::insertSort_XTo_S(std::vector<std::pair<int, int> > &container)
{
	int	i;

	for (std::vector<std::pair<int, int> >::iterator it = container.begin(); it != container.end(); it++)
	{
		if (it->first != -1 && it->first != _min_element_vector)
		{
			i = ::binarySearch(it->first, _Svector);
			_Svector.insert(_Svector.begin() + i, it->first);
		}
	}
	for (std::vector<std::pair<int, int> >::iterator it = container.begin(); it != container.end(); it++)
	{
		if (it->first == -1)
		{
			i = ::binarySearch(it->second, _Svector);
			_Svector.insert(_Svector.begin() + i, it->second);
		}
	}
}

std::vector<int>	PmergeMe::sort(std::vector<int> container)
{
	::printContainer(container, "Before: ");
	struct timespec begin;

	clock_gettime(CLOCK_MONOTONIC, &begin);
	std::ios_base::sync_with_stdio(false);

	if (container.size() == 1)
	{
		_Svector.push_back(container[0]);
		::printContainer(_Svector, "After:  ");
		::printTime(container, begin, "vector");
		return (_Svector);
	}
	createPairs(container);
	sortPairs(_Xvector);
	createAndSort_Svector(_Xvector);
	insertSort_XTo_S(_Xvector);
	::printContainer(_Svector, "After:  ");
	::printTime(container, begin, "vector");
	return (_Svector);
}

//! DEQUE OVERLOADS


void	PmergeMe::createPairs(std::deque<int> tab)
{
	for (std::deque<int>::iterator it = tab.begin(); it != tab.end(); it++)
	{
		if (it != tab.end() && it + 1 != tab.end())
		{
			std::pair<int, int>	tmp(*it, *(it + 1));
			_Xdeque.push_back(tmp);
			it++;
		}
		else
		{
			std::pair<int, int>	tmp(-1, *it);
			_Xdeque.push_back(tmp);
		}
	}
}

void	PmergeMe::sortPairs(std::deque<std::pair<int, int> > &container)
{
	for (std::deque<std::pair<int, int> >::iterator it = container.begin(); it != container.end(); it++)
	{
		if ( it->first > it->second)
		{
			std::swap(it->first, it->second);
		}
	}
}

std::pair<int, int>	PmergeMe::getPair(std::deque<std::pair<int, int> > tab, int second)
{
	for (std::deque<std::pair<int, int> >::iterator it = tab.begin(); it != tab.end(); it++)
	{
		if (it->second == second)
		{
			return (*it);
		}
	}
	return (std::pair<int, int> (-1, -1));
}

void	PmergeMe::createAndSort_Sdeque(std::deque<std::pair<int, int> > &container)
{
	int					min;
	std::pair<int, int>	pair;

	for (std::deque<std::pair<int, int> >::iterator it = container.begin(); it != container.end(); it++)
	{
		if (it->first != -1)
			_Sdeque.push_back(it->second);
	}
	std::sort(_Sdeque.begin(), _Sdeque.end());
	min = *std::min_element(_Sdeque.begin(), _Sdeque.end());
	_min_element_deque = getPair(container, min).first;
	_Sdeque.insert(_Sdeque.begin(), _min_element_deque);
}

void	PmergeMe::insertSort_XTo_S(std::deque<std::pair<int, int> > &container)
{
	int	i;

	for (std::deque<std::pair<int, int> >::iterator it = container.begin(); it != container.end(); it++)
	{
		if (it->first != -1 && it->first != _min_element_deque)
		{
			i = ::binarySearch(it->first, _Sdeque);
			_Sdeque.insert(_Sdeque.begin() + i, it->first);
		}
	}
	for (std::deque<std::pair<int, int> >::iterator it = container.begin(); it != container.end(); it++)
	{
		if (it->first == -1)
		{
			i = ::binarySearch(it->second, _Sdeque);
			_Sdeque.insert(_Sdeque.begin() + i, it->second);
		}
	}
}

std::deque<int>	PmergeMe::sort(std::deque<int> container)
{
	// ::printContainer(container, "Before: ");
	struct timespec begin;

	clock_gettime(CLOCK_MONOTONIC, &begin);
	std::ios_base::sync_with_stdio(false);

	if (container.size() == 1)
	{
		_Sdeque.push_back(container[0]);
		::printTime(container, begin, "deque");
		return (_Sdeque);
	}
	createPairs(container);
	sortPairs(_Xdeque);
	createAndSort_Sdeque(_Xdeque);
	insertSort_XTo_S(_Xdeque);
	// ::printContainer(_Sdeque, "After:  ");
	::printTime(container, begin, "deque");
	return (_Sdeque);
}
