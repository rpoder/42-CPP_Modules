/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 15:05:56 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/26 15:22:35 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.h"
#include <iostream>

int main(void)
{
	Data		test;
	Data		*ptr;
	uintptr_t	ptr_tmp;
	Data		*ptr_after;

	test.a = 1;
	test.b = 2;
	ptr = &test;

	// prints
	std::cout << "before:	"<< ptr << std::endl;
	std::cout << "b: " << ptr->b << std::endl;
	std::cout << "a: " << ptr->a << std::endl;
	ptr_tmp = Serializer::serialize(ptr);
	ptr_after = Serializer::deserialize(ptr_tmp);
	std::cout << "after:	"<< ptr_after << std::endl;
	std::cout << "a: " << ptr_after->a << std::endl;
	std::cout << "b: " << ptr_after->b << std::endl;
}
