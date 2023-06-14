/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 23:45:09 by bammar            #+#    #+#             */
/*   Updated: 2023/06/14 23:25:32 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "ft/vector.hpp"
#include <vector>

int main(void)
{
	ft::vector<int> mine;
	std::vector<int> stl;

	for (int i = 0; i < 5; i++)
	{
		mine.push_back(i);
		stl.push_back(i);
	}

	for (ft::vector<int>::reverse_iterator it = mine.rbegin(); it != mine.rend(); it++)
	{
		std::cout << *it << "\n";
	}
	
	std::cout << "------\n";

	for (std::vector<int>::reverse_iterator it = stl.rbegin(); it != stl.rend(); it++)
	{
		std::cout << *it << "\n";
	}
	return (0);
}
