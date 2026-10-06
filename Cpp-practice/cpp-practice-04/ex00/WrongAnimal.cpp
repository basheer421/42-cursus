/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 07:55:44 by bammar            #+#    #+#             */
/*   Updated: 2023/04/07 11:25:58 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal const called\n";
	this->type = "no-type";
}

WrongAnimal::WrongAnimal(const WrongAnimal& src)
{
	if (this != &src)
		*this = src;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& src)
{
	setType(src.getType());
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "" << "\n";
}

std::string WrongAnimal::getType() const
{
	return this->type;
}

void WrongAnimal::setType(std::string type)
{
	this->type = type;
}

WrongAnimal::~WrongAnimal() {}