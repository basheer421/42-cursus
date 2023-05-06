/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:19:41 by bammar            #+#    #+#             */
/*   Updated: 2023/04/05 01:08:45 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	setRawBits(0);
}

Fixed::Fixed(const Fixed& src)
{
	std::cout << "Copy constructor called\n";
	*this = src;
}

Fixed& Fixed::operator = (const Fixed &src)
{
	std::cout << "Copy assignment operator called\n";
	setRawBits(src.getRawBits());
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (this->fixed_num);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	this->fixed_num = raw;
}
