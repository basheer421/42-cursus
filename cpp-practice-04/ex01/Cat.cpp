/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 08:29:30 by bammar            #+#    #+#             */
/*   Updated: 2023/04/07 14:19:25 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat const called\n";
	this->type = "Cat";
	this->brain = new Brain();
	for (size_t i = 0; i < 100; i++)
		this->brain->ideas[i] = "cat_thoughts";
}

Cat::Cat(const Cat& src):Animal(src)
{
	*this = src;
}

Cat& Cat::operator = (const Cat& src)
{
	if (this == &src)
		return (*this);
	
	*(this->brain) = *src.getBrain();
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "meow" << "\n";
}

Brain *Cat::getBrain() const
{
	return (this->brain);
}

Cat::~Cat() 
{
	std::cout << "Cat dest\n";
	delete (this->brain);
}