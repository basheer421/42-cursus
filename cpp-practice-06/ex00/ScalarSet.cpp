/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarSet.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 23:29:21 by bammar            #+#    #+#             */
/*   Updated: 2023/06/08 17:50:34 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarSet.hpp"

ScalarSet::ScalarSet():Integer(0), Float(0), Double(0)
{
	NaN = false;
}

ScalarSet::ScalarSet(int Integer, float Float, double Double)
:Integer(Integer), Float(Float), Double(Double)
{
	NaN = false;
}

ScalarSet::ScalarSet(std::string s)
{
	NaN = true;
	Integer = -1;
	if (s == "nan" || s == "nanf")
	{
		this->sf = "nanf";
		this->sd = "nan";
	}
	else if (s == "inf" || s == "inff")
	{
		this->sf = "inff";
		this->sd = "inf";
	}
	else if (s == "-inf" || s == "-inff")
	{
		this->sf = "-inff";
		this->sd = "-inf";
	}
	else
	{
		this->sf = "";
		this->sd = "";
	}
}

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
	NaN = src.NaN;
	return (*this);
}

ScalarSet::~ScalarSet() {}

char ScalarSet::getCharacter() const 
{
	if ((Integer > 255) || Integer < 0)
		return (-1);
	return ((char)Integer);
}

