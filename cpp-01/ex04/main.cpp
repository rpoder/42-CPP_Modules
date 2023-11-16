/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:07:58 by rpoder            #+#    #+#             */
/*   Updated: 2023/02/20 15:33:15 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>

std::string	remplaceString(std::string str, std::string s1, std::string s2)
{
	size_t	find_index;

	find_index = 0;
	do {
		find_index = str.find(s1, find_index);
		if (find_index == std::string::npos)
			break;
		str.erase(find_index, s1.length());
		str.insert(find_index, s2);
		find_index += s2.length();
	} while (find_index != std::string::npos);
	return (str);
}

std::string	generateFilename(std::string filename)
{
	std::string	dst;

	dst = filename;
	dst += ".replace";
	return (dst);
}

int	main(int argc, char **argv)
{
	std::string			s1;
	std::string			s2;
	std::string			filename;
	std::ifstream		file;
	std::ofstream		outfile;
	std::stringstream	file_stream;
	std::string			file_str;
	std::string			new_file_str;

	if (argc != 4)
	{
		std::cout << "ERR:	Wrong number of parameters." << std::endl;
		return (-1);
	}
	filename = argv[1];
	if (filename.length() == 0)
	{
		std::cout << "ERR:	filename is not a valid input." << std::endl;
		return (-1);
	}
	s1 = argv[2];
	if (s1.length() == 0)
	{
		std::cout << "ERR:	s1 is not a valid input." << std::endl;
		return (-1);
	}
	s2 = argv[3];
	file.open(filename.c_str());
	if (file.is_open() == false || file.fail() == true || file.bad() == true)
	{
		std::cout << "ERR:	Error on open." << std::endl;
		return (-1);
	}
	file.peek();
	if (file.fail() == true)
	{
		std::cout << "ERR:	Error on open." << std::endl;
		return (-1);
	}
	file_stream << file.rdbuf();
	new_file_str = remplaceString(file_stream.str(), s1, s2);
	outfile.open(generateFilename(filename).c_str(), std::ofstream::out);
	if (outfile.is_open() == false || outfile.fail() == true || outfile.bad() == true)
	{
		std::cout << "ERR:	Error on outfile." << std::endl;
		file.close();
		if (outfile.is_open() == true)
			outfile.close();
		return (-1);
	}
	outfile << new_file_str;
	file.close();
	outfile.close();
}
