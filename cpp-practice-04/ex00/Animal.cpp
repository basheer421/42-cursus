/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 07:55:44 by bammar            #+#    #+#             */
/*   Updated: 2023/04/07 11:25:58 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal const called\n";
	this->type = "no-type";
}

Animal::Animal(const Animal& src)
{
	if (this != &src)
		*this = src;
}

Animal& Animal::operator=(const Animal& src)
{
	setType(src.getType());
	return (*this);
}

void Animal::makeSound() const
{
	std::cout << "" << "\n";
}

std::string Animal::getType() const
{
	return this->type;
}

void Animal::setType(std::string type)
{
	this->type = type;
}

Animal::~Animal() {}