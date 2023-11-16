/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:20:07 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/06 14:57:26 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat: virtual public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat &copy);
		~WrongCat();

		WrongCat	&operator=(const WrongCat &copy);

		void	makeSound(void) const;

	private:
};

#endif
