/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 06:48:10 by bammar            #+#    #+#             */
/*   Updated: 2023/04/06 07:55:36 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name):
ClapTrap(name),ScavTrap(name),FragTrap(name){
	setPlainName(name);
	setName(name + std::string("_clap_name"));
	setAttackDamage(FragTrap::getAttackDamage());
	setHealthPoints(FragTrap::getHealthPoints());
	setEnergyPoints(ScavTrap::getEnergyPoints());
	std::cout << "Diamond Constructor of " << getName() << "\n";
}

DiamondTrap::DiamondTrap() {DiamondTrap("null");}

DiamondTrap::~DiamondTrap() {
	std::cout << "Diamond destructor of " << getName() << "\n";
}

void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void DiamondTrap::setPlainName(std::string n) {
	plainName = n;
}

void DiamondTrap::whoAmI() {
	std::cout << "name: " << getName()
		<< ", ClapTrap name: " << plainName << "\n";
}
