/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:31:10 by rpoder            #+#    #+#             */
/*   Updated: 2023/04/11 10:31:56 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <exception>
#include <stdexcept>

class RPN
{
	public:
		RPN();
		RPN(const RPN &copy);
		~RPN();

		RPN	&operator=(const RPN &copy);
		float	compute(std::string str);
	private:
		std::stack<float>	_Svectortack;

		float	doOp(char c);
};

#endif
