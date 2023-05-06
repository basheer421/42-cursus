/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:19:41 by bammar            #+#    #+#             */
/*   Updated: 2023/04/05 04:53:29 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	setRawBits(0);
}

Fixed::Fixed(int const n)
{
	std::cout << "Int constructor called\n";
	fromInt(n);
}

Fixed::Fixed(float const n)
{
	std::cout << "Float constructor called\n";
	fromFloat(n);
}

Fixed::Fixed(const Fixed& src)
{
	std::cout << "Copy constructor called\n";
	this->operator=(src);
}

Fixed &Fixed::operator = (const Fixed &src)
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
	return (this->fixed_num);
}

void Fixed::setRawBits(int const raw)
{
	this->fixed_num = raw;
}


void Fixed::fromFloat(float const n)
{
	float offset;

	if (n >= 0)
		offset = 0.5;
	else
		offset = -0.5;
	setRawBits((float)n * (float)(1 << bit_count) + offset);
}

void Fixed::fromInt(int const n)
{
	fromFloat((float)n);
}

float Fixed::toFloat(void) const
{
	return ((float)getRawBits() / (float)(1 << bit_count));
}

int Fixed::toInt(void) const
{
	return ((int)(toFloat()));
}

std::ostream& operator << (std::ostream& out, const Fixed& fixed)
{
	if ((fixed.getRawBits() << (32 - 8)) > 0)
		out << fixed.toFloat();
	else {
		out << fixed.toInt();
	}
	return (out);
}
