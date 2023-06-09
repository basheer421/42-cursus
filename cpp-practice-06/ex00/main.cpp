/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:24:36 by bammar            #+#    #+#             */
/*   Updated: 2023/06/09 16:40:33 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	std::string s(argv[1]);
	try
	{
		ScalarSet set(ScalarConverter::convert(s));
		std::cout << "char: ";
		if (set.getCharacter() == -1)
			std::cout << "impossible\n";
		else if (!std::isprint(set.getCharacter()))
			std::cout << "Non displayable\n";
		else
			std::cout << "\'" <<set.getCharacter() << "\'" << "\n";
		
		std::cout << "int: ";
		if (!set.NaN)
			std::cout << set.Integer << "\n";
		else
			std::cout << "impossible\n";
		
		
		std::cout << "float: ";
		if (set.NaN)
		{
			std::cout << set.sf << "\n";
			std::cout << "double: ";
			std::cout << set.sd << "\n";
		} else 
		{
			std::cout << std::fixed << std::setprecision(1) << set.Float;
			std::cout << "f" << "\n";
			std::cout << "double: ";
			std::cout << std::fixed << std::setprecision(1) << set.Double << "\n";
		}
	
	} catch (std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}
	return (0);
}
