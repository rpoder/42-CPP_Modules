/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:23:12 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/06 17:42:48 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	public:
		Brain();
		Brain(const Brain &copy);
		~Brain();

		Brain		&operator=(const Brain &copy);

		void		setIdea(size_t index, std::string str);
		std::string	getIdea(size_t index);

	private:
		std::string	_ideas[100];
};

#endif
