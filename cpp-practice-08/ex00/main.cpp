/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 00:52:58 by bammar            #+#    #+#             */
/*   Updated: 2023/06/11 01:03:19 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <string>
#include <iostream>

int main(void)
{
	std::vector<int> cont;
	std::vector<std::string> badCont;

	for (int i = 0; i < 30; i++)
	{
		cont.push_back(i * 2);
		std::cout << cont[i] << " ";
	}
	std::cout << "\n";
	std::cout << "Value at index 2: " << cont[2] << "\n";
	std::cout << "Position: " << easyfind(cont, 4) << "\n";
	std::cout << "Position: " << easyfind(cont, 8) << "\n";
	std::cout << "Position: " << easyfind(cont, 128) << "\n"; // -1 (not found)
	std::cout << "Position: " << easyfind(cont, 58) << "\n";


	std::cout << "------\n";
	for (int i = 0; i < 10; i++)
	{
		badCont.push_back("hi");
		std::cout << badCont[i] << " ";
	}
	std::cout << "\n";

	// Doesn't compile
	// easyfind(badCont, -1);
	return 0;
}
