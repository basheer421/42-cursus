/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 07:08:20 by bammar            #+#    #+#             */
/*   Updated: 2023/04/05 08:17:10 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point():x(0),y(0){}

Point& Point::operator=(const Point &src)
{
	(void)src;
	return (*this);
}

Point::Point(const Point& src):x(src.getX()),y(src.getY()){}

Point::Point(const float x, const float y):x(Fixed(x)),y(Fixed(y)){}

const Fixed& Point::getX() const
{
	return (x);
}

const Fixed& Point::getY() const
{
	return (y);
}

Point::~Point(){}
