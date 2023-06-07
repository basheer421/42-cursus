/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:24:36 by bammar            #+#    #+#             */
/*   Updated: 2023/06/07 23:10:05 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(void)
{
	std::string s("13.3954545454");
	try
	{
		std::stringstream stream;

		ScalarSet set(ScalarConverter::convert(s));
		std::cout << set.Integer << "\n";
		if (set.getCharacter() == -1)
			std::cout << "impossible\n";
		else if (!std::isprint(set.getCharacter()))
			std::cout << "Non displayable\n";
		else
			std::cout << set.getCharacter() << "\n";

		stream << set.Float;
		std::cout << stream.str() << "f" << "\n";
		stream.clear();
		stream.seekg(0);
		stream.seekp(0);
		stream << set.Double;
		std::cout << stream.str() << "\n";
	
	} catch (std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}
	return (0);
}
