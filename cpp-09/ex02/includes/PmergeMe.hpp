/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:46:36 by rpoder            #+#    #+#             */
/*   Updated: 2023/04/11 10:42:42 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <deque>
# include <vector>
# include <utility>
# include <algorithm>
# include <tgmath.h>
# include "utils.hpp"
# include <ctime>
# include <iomanip>
# include <bits/stdc++.h>
# include <sys/time.h>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &copy);

		~PmergeMe();

		PmergeMe	&operator=(const PmergeMe &copy);

		std::vector<int>	sort(std::vector<int> tab);
		std::deque<int>		sort(std::deque<int> tab);

	private:
		std::vector<std::pair<int, int> >	_Xvector;
		std::vector<int>					_Svector;

		void				createPairs(std::vector<int> tab);
		void				sortPairs(std::vector<std::pair<int, int> > &container);
		void				createAndSort_Svector(std::vector<std::pair<int, int> > &container);
		std::pair<int, int>	getPair(std::vector<std::pair<int, int> > tab, int second);
		void				insertSort_XTo_S(std::vector<std::pair<int, int> > &container);
		int					_min_element_vector;

		std::deque<std::pair<int, int> >	_Xdeque;
		std::deque<int>						_Sdeque;

		void				createPairs(std::deque<int> tab);
		void				sortPairs(std::deque<std::pair<int, int> > &container);
		void				createAndSort_Sdeque(std::deque<std::pair<int, int> > &container);
		std::pair<int, int>	getPair(std::deque<std::pair<int, int> > tab, int second);
		void				insertSort_XTo_S(std::deque<std::pair<int, int> > &container);
		int					_min_element_deque;
};

#endif
