/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:24:36 by bammar            #+#    #+#             */
/*   Updated: 2023/06/05 15:26:44 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(void)
{
	std::string s("Y");
	ScalarSet set(ScalarConverter::convert(s));

	std::cout << set.Integer << "\n";
	std::cout << set.Character << "\n";
	std::cout << set.Float << "\n";
	std::cout << set.Double << "\n";
	return (0);
}
