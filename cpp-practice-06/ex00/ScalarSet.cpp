/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarSet.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 23:29:21 by bammar            #+#    #+#             */
/*   Updated: 2023/06/04 23:56:09 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarSet.hpp"

ScalarSet::ScalarSet():Character(0), Integer(0), Float(0), Double(0)
{}

ScalarSet::ScalarSet(char Character, int Integer, float Float, double Double)
:Character(Character), Integer(Integer), Float(Float), Double(Double)
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
	this->Character = src.Character;
	this->Integer = src.Integer;
	this->Double = src.Double;
	this->Float = src.Float;
	return (*this);
}

ScalarSet::~ScalarSet() {}
