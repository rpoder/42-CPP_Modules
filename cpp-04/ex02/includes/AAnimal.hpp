/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:03:07 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/06 18:20:33 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>

class AAnimal
{
	public:
		AAnimal();
		AAnimal(const std::string &type);
		AAnimal(const AAnimal &copy);
		virtual ~AAnimal();

		virtual AAnimal	&operator=(const AAnimal &copy);

		std::string	getType() const;

		virtual void	makeSound(void) const = 0;

	protected:
		std::string	_type;
};

#endif
