/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:09:21 by bammar            #+#    #+#             */
/*   Updated: 2023/04/05 04:45:32 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <string>
#include <iostream>

/**
 * Fixed point number inside an int (4 bytes)
*/
class Fixed
{
private:
	int					fixed_num;
	static const int	bit_count = 8;
	
public:
	Fixed();
	Fixed (const Fixed& src);
	Fixed& operator = (const Fixed& src);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif