/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 23:33:42 by bammar            #+#    #+#             */
/*   Updated: 2023/06/10 00:04:03 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <string>
#include <iostream>

int main(void)
{
	Array<std::string> strs(5);
	Array<int> ints(7);

	strs[1] = "wow";
	for (unsigned int i = 0; i < strs.size(); i++)
		std::cout << strs[i] << ", ";
	std::cout << "\n";
	for (unsigned int i = 0; i < strs.size(); i++)
		strs[i] = "string";
	for (unsigned int i = 0; i < strs.size(); i++)
		std::cout << strs[i] << ", ";
	std::cout << "\n";

	for (unsigned int i = 0; i < ints.size(); i++)
		ints[i] = i;
	for (unsigned int i = 0; i < ints.size(); i++)
		std::cout << ints[i] << ", ";
	std::cout << "\n";

	try {
		std::cout << ints[100] + 1 << "\n";
	} catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}

	return 0;
}