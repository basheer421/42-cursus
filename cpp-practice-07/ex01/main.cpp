/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 22:56:12 by bammar            #+#    #+#             */
/*   Updated: 2023/06/09 22:59:24 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

void addOne(int& x)
{
	++x;
}

int main(void)
{
	int arr[] = {1, 2, 3};
	int len  = 3;
	for (int i = 0; i < len; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\n";
	iter(arr, len, addOne);
	for (int i = 0; i < len; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\n";
	return 0;
}
