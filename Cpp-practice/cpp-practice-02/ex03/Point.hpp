/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 07:02:33 by bammar            #+#    #+#             */
/*   Updated: 2023/04/05 07:27:41 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	Fixed const x;
	Fixed const y;

public:
	Point();
	Point(const Point& src);
	Point(const float x, const float y);
	Point& operator=(const Point &src);
	~Point();
	const Fixed& getX() const;
	const Fixed& getY() const;
	
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif // POINT_HPP
