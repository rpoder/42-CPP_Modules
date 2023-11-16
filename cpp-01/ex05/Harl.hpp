/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ronanpoder <ronanpoder@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:08:58 by rpoder            #+#    #+#             */
/*   Updated: 2023/02/03 09:11:26 by ronanpoder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <fstream>
# include <sstream>

class	Harl
{
	public:
		Harl();
		~Harl();
		void complain( std::string level );

	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
};

#endif
