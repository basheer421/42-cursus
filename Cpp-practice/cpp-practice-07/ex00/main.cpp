/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 22:35:09 by bammar            #+#    #+#             */
/*   Updated: 2023/06/09 22:48:16 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

int main(void)
{

	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
	// int x = 1;
	// int y = 2;
	// double d1 = -1.2;
	// double d2 = 10.2;

	// ::swap(x, y);
	// std::cout << x << "\n";
	// std::cout << y << "\n";	

	// std::cout << "----\n";

	// std::cout << ::max(x, y) << "\n";
	// std::cout << ::min(x, y) << "\n";

	// std::cout << "----\n";

	// std::cout << ::max(d1, d2) << "\n";
	// std::cout << ::min(d1, d2) << "\n";s

	return 0;
}
