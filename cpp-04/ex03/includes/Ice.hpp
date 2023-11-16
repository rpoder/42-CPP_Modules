/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:47:14 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/08 19:26:10 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice:
	virtual public AMateria
{
	public:
		Ice();
		Ice(const Ice &copy);
		~Ice();

		Ice	&operator=(const Ice &copy);

		AMateria	*clone() const;
		void		use(ICharacter &target);
};

#endif
