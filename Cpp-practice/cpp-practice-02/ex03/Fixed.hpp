/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:09:21 by bammar            #+#    #+#             */
/*   Updated: 2023/04/05 06:43:43 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <ostream>
#include <cmath>

/**
 * Fixed point number inside an int (4 bytes)
 */
class Fixed
{
private:
	int fixed_num;
	static const int bit_count;

	void fromFloat(float const n);
	void fromInt(int const n);

public:
	Fixed();
	Fixed(int const n);
	Fixed(float const n);
	Fixed(const Fixed &src);
	~Fixed();

	Fixed &operator=(const Fixed &src);

	bool operator>(const Fixed &fixed) const;
	bool operator>=(const Fixed &fixed) const;
	bool operator<(const Fixed &fixed) const;
	bool operator<=(const Fixed &fixed) const;
	bool operator==(const Fixed &fixed) const;
	bool operator!=(const Fixed &fixed) const;

	Fixed operator+(const Fixed &fixed) const;
	Fixed operator-(const Fixed &fixed) const;
	Fixed operator*(const Fixed &fixed) const;
	Fixed operator/(const Fixed &fixed) const;

	// Preincrement
	Fixed &operator++();

	// Predecrement
	Fixed &operator--();

	// Postincrement
	Fixed operator++(int);

	// Postdecrement
	Fixed operator--(int);

	static Fixed& min(Fixed& f1, Fixed& f2);
	static const Fixed& min(const Fixed& f1, const Fixed& f2);
	static Fixed& max(Fixed& f1, Fixed& f2);
	static const Fixed& max(const Fixed& f1, const Fixed& f2);

	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif