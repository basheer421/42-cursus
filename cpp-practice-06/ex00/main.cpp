/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:24:36 by bammar            #+#    #+#             */
/*   Updated: 2023/06/05 20:43:43 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(void)
{
	std::string s("65");
	ScalarSet set(ScalarConverter::convert(s));

	std::cout << set.Integer << "\n";
	if (set.getCharacter() == -1)
		std::cout << "impossible\n";
	else if (!std::isprint(set.getCharacter()))
		std::cout << "Non displayable\n";
	else
		std::cout << set.getCharacter() << "\n";
	std::cout << set.Float << "\n";
	std::cout << set.Double << "\n";
	return (0);
}
