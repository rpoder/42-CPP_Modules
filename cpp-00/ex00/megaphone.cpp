/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:22:21 by ronanpoder        #+#    #+#             */
/*   Updated: 2023/02/05 14:56:48 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
	int		i;
	int		j;
	char	c;

	i = 1;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while(i < argc)
		{
			j = 0;
			while(argv[i][j])
			{
				c = toupper(argv[i][j]);
				std::cout << c;
				j++;
			}
			i++;
		}
		std::cout << std::endl;
	}
}
