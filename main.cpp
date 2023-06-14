/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 23:45:09 by bammar            #+#    #+#             */
/*   Updated: 2023/06/14 17:53:19 by bammar           ###   ########.fr       */
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
	mine2.assign(mine.begin(), mine.begin() + 2);
	stl.assign(5, 2);
	stl2.assign(stl.begin(), stl.begin() + 2);
	for (size_t i = 0; i < mine.size(); i++)
	{
		std::cout << mine.at(i) << "\n";
	}

	std::cout << "-----\n";

	for (size_t i = 0; i < stl.size(); i++)
	{
		std::cout << stl.at(i) << "\n";
	}

	std::cout << "------\nIterators:\n";
	int x = 0;
	for (ft::vector<int>::iterator it = mine.begin(); it != mine.end(); it++)
	{
		*it = ++x;
		std::cout << *it << "\n";
	}

	std::cout << "/-----\n";
	// mine.erase(mine.begin()+2, mine.begin());
	for (ft::vector<int>::iterator it = mine.begin(); it != mine.end(); it++)
	{
		std::cout << *it << "\n";
	}

	std::cout << "-----\nstl:----\n\n";

	x = 0;
	for (std::vector<int>::iterator it = stl.begin(); it != stl.end(); it++)
	{
		*it = ++x;
		std::cout << *it << "\n";
	}

	std::cout << "/-----\n";
	stl.erase(stl.begin()+2, stl.begin());
	for (std::vector<int>::iterator it = stl.begin(); it != stl.end(); it++)
	{
		std::cout << *it << "\n";
	}
	return (0);
}
