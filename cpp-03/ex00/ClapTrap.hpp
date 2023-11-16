/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:36:26 by ronanpoder        #+#    #+#             */
/*   Updated: 2023/03/03 15:59:05 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CLAPTRAP_HPP_
# define _CLAPTRAP_HPP_

#include <iostream>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(const std::string &name);
		ClapTrap(const ClapTrap &rhs);
		~ClapTrap();

		ClapTrap	&operator=(const ClapTrap &rhs);

		std::string	getName() const;
		int			getHitPoint() const;
		int			getEnergyPoint() const;
		int			getAttackDamage() const;
		void		setName(std::string name);
		void		setHitPoint(int hit_point);
		void		setEnergyPoint(int energy_point);
		void		setAttackDamage(int attack_damage);

		void		attack(const std::string &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

	private:
		std::string	_name;
		int			_hit_point;
		int			_energy_point;
		int			_attack_damage;

		bool		isAlive() const;
		bool		hasEnergyPoint() const;
};

#endif
