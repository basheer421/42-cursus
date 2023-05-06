/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:29:47 by bammar            #+#    #+#             */
/*   Updated: 2023/04/05 22:00:51 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void) {
	
	{
		Fixed a(0.5f);
		Fixed b(42.42f);
		Fixed c;
		c = Fixed(1234.2321f);
		std::cout << "value of a: " << a.toFloat() << std::endl;
		std::cout << "value of b: " << b << std::endl;
		std::cout << "value of c: " << c << std::endl;
		std::cout << "value of a+b: " << a+b << std::endl;
		std::cout << "value of b*a: " << b*a << std::endl;
		std::cout << "value of c-c: " << c-c << std::endl;
	}
	std::cout << "\nSection 2:\n\n";
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}
	return (0);
}