/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:47:14 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/08 19:26:10 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure:
	virtual public AMateria
{
	public:
		Cure();
		Cure(const Cure &copy);
		~Cure();

		Cure	&operator=(const Cure &copy);

		AMateria	*clone() const;
		void		use(ICharacter &target);
};

#endif
