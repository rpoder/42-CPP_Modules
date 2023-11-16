/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:30:42 by rpoder            #+#    #+#             */
/*   Updated: 2023/04/11 10:31:56 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include "RPN.hpp"

//!-------------------------------CONSTRUCTOR-----------------------------------

RPN::RPN()
{

}

RPN::RPN(const RPN &copy)
{
	*this = copy;
}

//!-------------------------------DESTRUCTOR------------------------------------

RPN::~RPN()
{

}

//!-------------------------------OPERATOR--------------------------------------

RPN	&RPN::operator=(const RPN &copy)
{
	_Svectortack = copy._Svectortack;
	return(*this);
}

//!-------------------------------FUNCTIONS-------------------------------------

bool	isOperator(char c)
{
	if (c == '+' || c == '-' || c == '/' || c == '*')
		return (true);
	return (false);
}

float	RPN::doOp(char c)
{
	float	a;

	if (_Svectortack.size() <= 1)
		throw(std::invalid_argument("Only one number in stack"));
	switch (c)
	{
		case '+':
		{
			a = _Svectortack.top();
			_Svectortack.pop();
			return (a + _Svectortack.top());
		}
		case '-':
		{
			a = _Svectortack.top();
			_Svectortack.pop();
			return ( _Svectortack.top() - a);
		}
		case '/':
		{
			a = _Svectortack.top();
			_Svectortack.pop();
			if (a == 0)
				throw(std::invalid_argument("division by 0"));
			return (_Svectortack.top() / a);
		}
		case '*':
		{
			a = _Svectortack.top();
			_Svectortack.pop();
			return (a * _Svectortack.top());
		}
	}
	return (0);
}

float	RPN::compute(std::string str)
{
	size_t	i;
	float	res;

	i = 0;
	while (str[i])
	{
		if (!isOperator(str[i]) && std::isdigit(str[i]))
		{
			_Svectortack.push(str[i] - 48);
		}
		else if (isOperator(str[i]))
		{
			res = doOp(str[i]);
			_Svectortack.pop();
			_Svectortack.push(res);
		}
		else if (str[i] != ' ')
			throw(std::invalid_argument(str));
		i++;

		while (str[i] && isOperator(str[i]))
		{
			res = doOp(str[i]);
			_Svectortack.pop();
			_Svectortack.push(res);
			i++;
		}
	}
	if (!isOperator(str[i - 1]) || _Svectortack.size() != 1)
			throw(std::invalid_argument(str));
	return (_Svectortack.top());
}
