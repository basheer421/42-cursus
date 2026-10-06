/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:29:47 by bammar            #+#    #+#             */
/*   Updated: 2023/04/05 05:00:02 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void) {
	
	Fixed a(33.68f);
	Fixed b(42.42f);
	Fixed c;
	Fixed d(-33.68f);
	c = Fixed(1234.2321f);
	std::cout << "value of a: " << a << std::endl;
	std::cout << "value of b: " << b << std::endl;
	std::cout << "value of c: " << c << std::endl;
	std::cout << "value of d: " << d << std::endl;
	return 0;
}