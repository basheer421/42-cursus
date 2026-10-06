/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:26:10 by bammar            #+#    #+#             */
/*   Updated: 2023/04/08 15:27:48 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure():AMateria("cure") {}

Cure::~Cure() {}

Cure::Cure(const Cure& src):AMateria(src)
{
	*this = src;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "\'s wounds *\n";
}

Cure* Cure::clone() const
{
	return (new Cure());
}
