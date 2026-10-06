/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 22:36:14 by bammar            #+#    #+#             */
/*   Updated: 2023/02/19 18:00:30 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

static std::string text_from_file(std::string fname)
{
	std::stringstream	stream;
	std::string			text;
	std::fstream		file_in(fname, std::fstream::in);
	if (!file_in.is_open())
		return ("");
	stream << file_in.rdbuf();
	text = stream.str();
	file_in.close();
	return (text);
}

int main(int argc, char **argv)
{
	std::string text;
	std::string toFind;
	std::string	replacment;
	size_t		pos;
	
	if (argc != 4 || !*argv[1] || !*argv[2])
		return (1);	
	text = text_from_file(std::string(argv[1]));
	if (text.length() == 0)
		return (1);
	std::fstream file_out(std::string(argv[1]).append(".replace"),
		std::fstream::out | std::fstream::trunc);
	if (!file_out.is_open())
		return (1);
	toFind = std::string(argv[2]);
	replacment = std::string(argv[3]);
	pos = text.find(toFind);
	while (pos != 0 && pos < text.length())
	{
		file_out << text.substr(0, pos) << replacment;
		text = text.substr(pos + toFind.length());
		pos = text.find(toFind);
	}
	file_out << text;
	return (file_out.close(), 0);
}
