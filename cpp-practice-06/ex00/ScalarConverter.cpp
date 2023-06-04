/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:24:31 by bammar            #+#    #+#             */
/*   Updated: 2023/06/05 00:15:34 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarSet ScalarConverter::convert(const std::string s)
{
	std::stringstream	stream;
	ScalarSet			set;

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
