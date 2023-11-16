/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:27:12 by rpoder            #+#    #+#             */
/*   Updated: 2023/04/04 11:15:50 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cctype>

const std::string	trimKey(std::string str, char sep);
const std::string	trimValue(std::string str, char sep);
bool				isValidDate(std::string date);

#endif
