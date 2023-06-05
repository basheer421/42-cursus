/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:24:31 by bammar            #+#    #+#             */
/*   Updated: 2023/06/05 15:26:20 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// removes leading and ending spaces
void ScalarConverter::stripSpaces(std::string& s)
{
	size_t sPos;
	size_t end;

	sPos = 0;
	while (sPos < s.length() && std::isspace(s[sPos]))
		++sPos;
	end = sPos;
	while (end < s.length() && !std::isspace(s[end]))
		++end;
	s = s.substr(sPos, end-sPos);
	return ;
}

ScalarConverter::t_type ScalarConverter::getType(std::string& s)
{
	// std::string::iterator it;
	t_type t = NONE;
	(void)s;
	
	// if (std::isalpha(*it) && it+1 == s.end())
	// 	t = CHAR;
	return (t);
}

ScalarSet ScalarConverter::convert(std::string s)
{
	std::stringstream	stream;
	ScalarSet			set;

	ScalarConverter::stripSpaces(s);
	// getType(s);
	std::cout << "string:" << s << "$" << "\n";
	stream << s;
	stream >> set.Integer;

	stream.clear();
	stream.seekg(0);
	stream.seekp(0);
	stream << s;
	stream >> set.Character;
	
	stream.clear();
	stream.seekg(0);
	stream.seekp(0);
	stream << s;
	stream >> set.Double;
	
	stream.clear();
	stream.seekg(0);
	stream.seekp(0);
	stream << s;
	stream >> set.Float;
	return (set);
}
