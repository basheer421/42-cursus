/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:24:31 by bammar            #+#    #+#             */
/*   Updated: 2023/06/07 23:00:27 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

const char *ScalarConverter::InvalidTypeException::what() const throw()
{
	return ("Invalid Type");
}

static bool isInt(const std::string& s)
{
	for (size_t i = 0; i < s.length(); i++)
	{
		if (!std::isdigit(s[i]))
			return (false);
	}
	return (true);
}

static bool isFloat(const std::string& s)
{
	bool pointReached = false;

	for (size_t i = 0; i < s.length() - 1; i++)
	{
		if (!std::isdigit(s[i]))
		{
			if (!pointReached && s[i] == '.')
				pointReached = true;
			else if (pointReached || s[i] != '.')
				return (false);
		}
	}
	return (true);
}

ScalarConverter::t_type ScalarConverter::getType(std::string& s)
{
	size_t i;

	if ((s.length() == 1) && !std::isdigit(s[0]))
		return (CHAR);
	for (i = 0; i < s.length() && (s[i] == '+' || s[i] == '-'); i++)
	{
		;
	}	
	for (; i < s.length(); i++) {
		if (!std::isdigit(s[i]))
			return (NONE);
		else if (isInt(s.substr(i)))
			return (INT);
		else if (isFloat(s.substr(i)))
		{
			if (s[s.length() - 1] == 'f')
				return (FLOAT);
			if (std::isdigit(s[s.length() - 1]))
				return (DOUBLE);
			return (NONE);
		}
	}
	return (NONE);
}

ScalarSet ScalarConverter::convert(std::string s)
{
	std::stringstream	stream;
	ScalarSet			set;
	t_type				type;

	type = ScalarConverter::getType(s);
	if (type == NONE)
		throw InvalidTypeException();
	if (type == FLOAT)
		s = s.substr(0, s.length() - 1);

	stream << s;
	stream >> set.Integer;

	set.getCharacter();

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
