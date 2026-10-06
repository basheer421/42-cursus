/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:19:41 by bammar            #+#    #+#             */
/*   Updated: 2023/04/05 21:47:24 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::bit_count = 8;

Fixed::Fixed()
{
	setRawBits(0);
}

Fixed::Fixed(int const n)
{
	fromInt(n);
}

Fixed::Fixed(float const n)
{
	fromFloat(n);
}

Fixed::Fixed(const Fixed &src)
{
	this->operator=(src);
}

Fixed &Fixed::operator=(const Fixed &src)
{
	setRawBits(src.getRawBits());
	return (*this);
}

Fixed::~Fixed()
{
	
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

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	if ((fixed.getRawBits() << (32 - 8)) > 0)
		out << fixed.toFloat();
	else
	{
		out << fixed.toInt();
	}

	return (out);
}

bool Fixed::operator>(const Fixed &fixed) const
{
	return (this->getRawBits() > fixed.getRawBits());
}

bool Fixed::operator>=(const Fixed &fixed) const
{
	return (this->getRawBits() >= fixed.getRawBits());
}

bool Fixed::operator<(const Fixed &fixed) const
{
	return (this->getRawBits() < fixed.getRawBits());
}

bool Fixed::operator<=(const Fixed &fixed) const
{
	return (this->getRawBits() <= fixed.getRawBits());
}

bool Fixed::operator==(const Fixed &fixed) const
{
	return (this->getRawBits() == fixed.getRawBits());
}

bool Fixed::operator!=(const Fixed &fixed) const
{
	return (this->getRawBits() != fixed.getRawBits());
}

Fixed Fixed::operator+(const Fixed &fixed) const
{
	Fixed x;
	x.setRawBits(this->getRawBits() + fixed.getRawBits());
	return (x);
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
	Fixed x;
	x.setRawBits(this->getRawBits() - fixed.getRawBits());
	return (x);
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
	Fixed x;
	x.setRawBits(((long)this->getRawBits() * (long)fixed.getRawBits()) >> bit_count);
	return (x);
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
	Fixed x;
	x.setRawBits(((long)this->getRawBits() << bit_count) / (long)fixed.getRawBits());
	return (x);
}

Fixed &Fixed::operator++()
{
	Fixed x;

	x.setRawBits(1);
	*this = *this + x; 
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed oldVal;

	oldVal = *this;
	++(*this);
	return (oldVal);
}

Fixed &Fixed::operator--()
{
	Fixed x;

	x.setRawBits(1);
	*this = *this - x; 
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed oldVal;

	oldVal = *this;
	--(*this);
	return (oldVal);
}

const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2)
{
	if (f1 > f2)
		return (f2);
	return (f1);
}

Fixed& Fixed::min(Fixed& f1, Fixed& f2)
{
	if (f1 > f2)
		return (f2);
	return (f1);;
}

const Fixed& Fixed::max(const Fixed& f1, const Fixed& f2)
{
	if (f1 > f2)
		return (f1);
	return (f2);
}

Fixed& Fixed::max(Fixed& f1, Fixed& f2)
{
	if (f1 > f2)
		return (f1);
	return (f2);
}
