/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:56:18 by rpoder            #+#    #+#             */
/*   Updated: 2023/04/05 11:59:47 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T1>
void	iter(T1 *tab, int len, void(* function)(const T1 &))
{
	int	i;

	i = 0;
	while (i < len)
	{
		function(tab[i]);
		i++;
	}
}

// template <typename T1>
// void	iter(T1 *tab, int len, void(* function)(T1 &))
// {
// 	int	i;

// 	i = 0;
// 	while (i < len)
// 	{
// 		function(tab[i]);
// 		i++;
// 	}
// }


