/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:03:07 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/06 12:36:58 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(const std::string &type);
		WrongAnimal(const WrongAnimal &copy);
		virtual ~WrongAnimal();

		WrongAnimal	&operator=(const WrongAnimal &copy);

		std::string	getType() const;

		void	makeSound(void) const;

	protected:
		std::string	_type;
};

#endif
