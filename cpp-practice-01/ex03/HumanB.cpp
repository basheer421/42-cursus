/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:58:03 by bammar            #+#    #+#             */
/*   Updated: 2023/02/17 22:33:42 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = nullptr;
}

std::string HumanB::getName(void)
{
	return name;
}

Weapon &HumanB::getWeapon(void)
{
	return *weapon;
}

void HumanB::setName(std::string name)
{
	this->name = name;
}

void HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}

void HumanB::attack(void)
{
	if (this->weapon == nullptr)
		std::cout <<
		this->name <<
		" attacks with their hand\n";
	else	
		std::cout <<
		this->name <<
		" attacks with their " <<
		this->weapon->getType() <<
		"\n";
}

HumanB::~HumanB(){};
