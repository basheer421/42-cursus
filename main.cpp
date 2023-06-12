/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 23:45:09 by bammar            #+#    #+#             */
/*   Updated: 2023/06/13 01:16:33 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "ft/vector.hpp"
#include <vector>

int main(void)
{
	ft::vector<int> mine;
	ft::vector<int> mine2;
	std::vector<int> stl;
	std::vector<int> stl2;

	mine.assign(5, 2);
	mine2.assign(3, 3);
	stl.assign(5, 2);
	stl2.assign(3, 3);

	mine2.swap(mine);
	mine.swap(mine);
	for (size_t i = 0; i < mine.size(); i++)
	{
		std::cout << mine.at(i) << "\n";
	}

	std::cout << "-----\n";
	stl2.swap(stl);
	stl.swap(stl);
	for (size_t i = 0; i < stl.size(); i++)
	{
		std::cout << stl.at(i) << "\n";
	}

	return (0);
}
