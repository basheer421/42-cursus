/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:24:31 by bammar            #+#    #+#             */
/*   Updated: 2023/06/05 20:35:41 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

const char *ScalarConverter::NonDisplayableException::what() const throw()
{
	return ("Non displayable");
}

const char *ScalarConverter::ImpossibleConversionException::what() const throw()
{
	return ("impossible");
}

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

ScalarSet ScalarConverter::convert(std::string s)
{
	std::stringstream	stream;
	ScalarSet			set;

	ScalarConverter::stripSpaces(s);
	stream << s;
	stream >> set.Integer;

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
