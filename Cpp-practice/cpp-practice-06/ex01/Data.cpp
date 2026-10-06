/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:24:23 by bammar            #+#    #+#             */
/*   Updated: 2023/06/09 17:40:58 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(){}

Data::Data(std::string type, std::string color, std::string size):
type(type), color(color), size(size)
{}

Data::~Data(){}

Data::Data(const Data& src) 
{
	if (this == &src)
		return ;
	*this = src;
}

Data& Data::operator = (const Data& src)
{
	if (this == &src)
		return *this;
	type = src.type;
	color = src.color;
	size = src.size;
	return (*this);
}
