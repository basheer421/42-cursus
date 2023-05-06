/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:08:57 by bammar            #+#    #+#             */
/*   Updated: 2023/02/17 22:34:25 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::Weapon()
{
	this->type = "hand";
}

std::string Weapon::getType(void)
{
	return this->type;
}

void Weapon::setType(std::string type)
{
	this->type = type;
}

Weapon::~Weapon(){};
