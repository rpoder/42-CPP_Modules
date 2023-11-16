/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:30:09 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/31 12:51:01 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
void	swap(T &parameter1, T &parameter2)
{
	T	tmp;

	tmp = parameter1;
	parameter1 = parameter2;
	parameter2 = tmp;
}

template <typename T>
T	min(T parameter1, T parameter2)
{
	if (parameter1 == parameter2)
		return (parameter2);
	if (parameter1 < parameter2)
		return (parameter1);
	else
		return (parameter2);
}

template <typename T>
T	max(T parameter1, T parameter2)
{
	if (parameter1 == parameter2)
		return (parameter2);
	if (parameter1 > parameter2)
		return (parameter1);
	else
		return (parameter2);
}
