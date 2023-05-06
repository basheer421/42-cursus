/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 08:15:57 by bammar            #+#    #+#             */
/*   Updated: 2023/04/07 14:33:48 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog const called\n";
	this->type = "Dog";
	this->brain = new Brain();
	for (size_t i = 0; i < 100; i++)
		this->brain->ideas[i] = "dog_thoughts";
}

Dog::Dog(const Dog& src):Animal(src)
{
	*this = src;
}

Dog& Dog::operator = (const Dog& src)
{
	if (this == &src)
		return (*this);
	
	*(this->brain) = *src.getBrain();
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "bark" << "\n";
}

Brain *Dog::getBrain() const
{
	return (this->brain);
}

Dog::~Dog() 
{
	std::cout << "Dog dest\n";
	delete (this->brain);
}