/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:14:17 by rpoder            #+#    #+#             */
/*   Updated: 2023/03/08 19:38:47 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource:
	public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &copy);
		~MateriaSource();

		MateriaSource		&operator=(const MateriaSource &copy);

		virtual void		learnMateria(AMateria *m);
		virtual AMateria	*createMateria(const std::string &type);

	private:
		AMateria			*_saved_materia[4];
};

#endif
