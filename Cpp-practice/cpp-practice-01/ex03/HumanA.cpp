/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:46:52 by bammar            #+#    #+#             */
/*   Updated: 2023/02/17 22:29:30 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon)
{
	this->weapon = &weapon;
	this->name = name;
};

std::string HumanA::getName(void)
{
	return name;
}

Weapon& HumanA::getWeapon(void)
{
	return *weapon;
}

void HumanA::setName(std::string name)
{
	this->name = name;
}

void HumanA::setWeapon(Weapon& weapon)
{
	*this->weapon = weapon;
}

void HumanA::attack(void)
{
	std::cout << this->name << " attacks with their " << this->weapon->getType() << "\n";
}

HumanA::~HumanA(){};
