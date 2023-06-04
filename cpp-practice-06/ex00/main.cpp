/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:24:36 by bammar            #+#    #+#             */
/*   Updated: 2023/06/05 00:15:58 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(void)
{
	std::string s("454.1");
	ScalarSet set(ScalarConverter::convert(s));

	std::cout << set.Integer << "\n";
	std::cout << set.Character << "\n";
	std::cout << set.Float << "\n";
	std::cout << set.Double << "\n";
	return (0);
}
