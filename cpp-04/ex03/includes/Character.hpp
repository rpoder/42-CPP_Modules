/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:23:24 by ronanpoder        #+#    #+#             */
/*   Updated: 2023/03/08 19:31:51 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character:
	public ICharacter
{
	public:
		Character();
		Character(std::string name);
		Character(const Character &copy);
		~Character();

		Character	&operator=(const Character &copy);

		const std::string	&getName(void) const;
		void				equip(AMateria *m);
		void				unequip(int idx);
		void				use(int idx, ICharacter &target);

	private:
		std::string	_name;
		AMateria	*_items[4];
};

#endif
