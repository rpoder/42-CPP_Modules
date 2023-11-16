/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:11:29 by rpoder            #+#    #+#             */
/*   Updated: 2023/04/05 12:03:14 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Array.hpp>
#define MAX_VAL 3

int main()
{
	Array<int>	numbers(MAX_VAL);
	Array<int>	test;
	int* mirror = new int[MAX_VAL];
	Array<int>	tmp(MAX_VAL);
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}


	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			delete[] mirror;
			return (1);
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	tmp = numbers;
	for (int i = 0; i < MAX_VAL; i++)
	{
		std::cout << "tmp[" << i << "] =	"<< tmp[i] << std::endl;
		std::cout << "numbers[" << i << "] =	"<< tmp[i] << std::endl;
		std::cout << std::endl;
	}
	delete[] mirror;
	return 0;
}
