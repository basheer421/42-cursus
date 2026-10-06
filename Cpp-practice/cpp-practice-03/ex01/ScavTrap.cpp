/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 06:48:10 by bammar            #+#    #+#             */
/*   Updated: 2023/04/06 07:54:48 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name):ClapTrap(name) {
	setAttackDamage(20);
	setHealthPoints(100);
	setEnergyPoints(50);
	std::cout << "Scav Constructor of " << getName() << "\n";
}

ScavTrap::ScavTrap() {ScavTrap("null");}

ScavTrap::~ScavTrap() {
	std::cout << "Scav destructor of " << getName() << "\n";
}

void ScavTrap::attack(const std::string& target) {
	if (getEnergyPoints() == 0 || getHealthPoints() == 0)
		return ;
	setEnergyPoints(getEnergyPoints() - 1);
	std::cout <<
		"ScavTrap " << getName() << " attacks " << target << ", causing "
		<< getAttackDamage() << " points of damage!\n";
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << getName() << " is now in Gate keeper mode\n";
}
