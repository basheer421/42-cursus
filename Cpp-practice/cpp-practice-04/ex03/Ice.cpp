/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:26:10 by bammar            #+#    #+#             */
/*   Updated: 2023/04/08 15:30:55 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice():AMateria("ice") {}

Ice::~Ice() {}

Ice::Ice(const Ice& src):AMateria(src)
{
	*this = src;
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at "
		<< target.getName() << " *\n";
}

Ice* Ice::clone() const
{
	return (new Ice());
}
