/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:28:40 by rpoder            #+#    #+#             */
/*   Updated: 2023/04/06 17:30:16 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int	main()
{
	std::cout << "--------------- TEST 1.1" << std::endl;
	{
		std::list<int>	test;

		test.push_back(11);
		test.push_back(22);
		test.push_back(33);
		for (std::list<int>::iterator it = test.begin(); it != test.end(); it++)
			std::cout << *it << std::endl;
	}
	std::cout << "--------------- TEST 1.2" << std::endl;
	{
		MutantStack<int> mstack;

		mstack.push(11);
		mstack.push(22);
		mstack.push(33);
		for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); it++)
			std::cout << *it << std::endl;
	}
	std::cout << "--------------- TEST 2.1" << std::endl;
	{
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << *mstack.rbegin() << std::endl;
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
	}
	std::cout << "--------------- TEST 2.2" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	return (0);
}
