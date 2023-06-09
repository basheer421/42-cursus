/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 22:35:09 by bammar            #+#    #+#             */
/*   Updated: 2023/06/09 22:45:44 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

int main(void)
{
	int x = 1;
	int y = 2;
	double d1 = -1.2;
	double d2 = 10.2;

	::swap(x, y);
	std::cout << x << "\n";
	std::cout << y << "\n";	

	std::cout << "----\n";

	std::cout << ::max(x, y) << "\n";
	std::cout << ::min(x, y) << "\n";

	std::cout << "----\n";

	std::cout << ::max(d1, d2) << "\n";
	std::cout << ::min(d1, d2) << "\n";

	return 0;
}
