/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:30:09 by rpoder            #+#    #+#             */
/*   Updated: 2023/04/06 16:46:27 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template <typename T>
typename T::iterator	eastfind(T container, int to_find)
{
	typename T::iterator	it;

	it = std::find(container.begin(), container.end(), to_find);
	if (it == container.end())
		throw (std::exception());
	return (it);

}

#endif
