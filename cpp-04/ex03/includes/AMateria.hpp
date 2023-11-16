/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:30:29 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/08 19:27:57 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>

class AMateria;
#include "ICharacter.hpp"

class AMateria
{
	public:
		AMateria();
		AMateria(const std::string &type);
		AMateria(const AMateria &copy);
		virtual ~AMateria();

		AMateria			&operator=(const AMateria &copy);

		virtual AMateria	*clone() const = 0;
		virtual void		use(ICharacter &target);
		std::string			getType() const;

	protected:
		std::string			_type;

	private:
};

#endif
