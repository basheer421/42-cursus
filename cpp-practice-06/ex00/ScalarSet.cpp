/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarSet.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 23:29:21 by bammar            #+#    #+#             */
/*   Updated: 2023/06/05 20:44:46 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarSet.hpp"

ScalarSet::ScalarSet():Integer(0), Float(0), Double(0)
{}

ScalarSet::ScalarSet(int Integer, float Float, double Double)
:Integer(Integer), Float(Float), Double(Double)
{}

ScalarSet::ScalarSet(const ScalarSet& src)
{
	if (this == &src)
		return ;
	*this = src;
}

ScalarSet & ScalarSet::operator = (const ScalarSet& src)
{
	if (this == &src)
		return (*this);
	this->Integer = src.Integer;
	this->Double = src.Double;
	this->Float = src.Float;
	return (*this);
}

ScalarSet::~ScalarSet() {}

char ScalarSet::getCharacter() const 
{
	if ((Integer > 255) || Integer < 0)
		return (-1);
	return ((char)Integer);
}
